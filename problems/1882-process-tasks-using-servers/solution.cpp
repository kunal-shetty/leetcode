// 1882. Process Tasks Using Servers
// Difficulty: Medium
// https://leetcode.com/problems/process-tasks-using-servers/
// Runtime: 167 ms (beats 41.1%)
// Memory: 141.5 MB (beats 75.5%)
// Submitted: 2026-11-07


class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        using T = tuple<long long, int, int>;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>> available;

        priority_queue<T, vector<T>, greater<T>> busy;

        int n = servers.size(), m = tasks.size();
        vector<int> res(m);

        for (int i = 0; i < n; i++)
            available.push({servers[i], i});

        long long time = 0;

        for (long long i = 0; i < m; i++) {
            time = max(time,i);

            while (!busy.empty() && get<0>(busy.top()) <= time) {
                auto [finish, weight, index] = busy.top();
                busy.pop();
                available.push({weight, index});
            }

            if (available.empty()) {
                time = get<0>(busy.top());

                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    auto [finish, weight, index] = busy.top();
                    busy.pop();
                    available.push({weight, index});
                }
            }

            auto [weight, index] = available.top();
            available.pop();

            res[i] = index;
            busy.push({time + tasks[i], weight, index});
        }

        return res;
    }
};
