// 2747. Count Zero Request Servers
// Difficulty: Medium
// https://leetcode.com/problems/count-zero-request-servers/
// Runtime: 2308 ms (beats 5.2%)
// Memory: 619.1 MB (beats 5.2%)
// Submitted: 2026-11-06


class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x,
                             vector<int>& queries) {
        sort(logs.begin(), logs.end(),
             [](auto a, auto b) { return a[1] < b[1]; });

        vector<int> order(queries.size()), count(n + 1), res(queries.size());
        iota(order.begin(), order.end(), 0);

        sort(order.begin(), order.end(),
             [&](int a, int b) { return queries[a] < queries[b]; });

        int busy = 0, left = 0, right = 0;

        for (int i : order) {
            int q = queries[i];

            while (right < logs.size() && logs[right][1] <= q) {
                int server = logs[right][0];

                if (count[server] == 0)
                    busy++;

                count[server]++;
                right++;
            }

            while (left < right && logs[left][1] < q - x) {
                int server = logs[left][0];

                count[server]--;

                if (count[server] == 0)
                    busy--;

                left++;
            }
            res[i] = n - busy;
        }

        return res;
    }
};
