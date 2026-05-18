// 1345. Jump Game IV
// Difficulty: Hard
// https://leetcode.com/problems/jump-game-iv/
// Runtime: 69 ms (beats —)
// Memory: 74.6 MB (beats —)
// Submitted: 2026-05-18

class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        if (n == 1)
            return 0;

        unordered_map<int, vector<int>> map;
        int step = 0;

        for (int i = 0; i < n; i++) {
            map[arr[i]].push_back(i);
        }

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            step++;
            int size = q.size();
            for (int i = 0; i < size; i++) {
                int j = q.front();
                q.pop();

                if (j - 1 >= 0 && map.find(arr[j - 1]) != map.end()) {
                    q.push(j - 1);
                }

                if (j + 1 < n && map.find(arr[j + 1]) != map.end()) {
                    if (j + 1 == n - 1)
                        return step;
                    q.push(j + 1);
                }

                if (map.find(arr[j]) != map.end()) {
                    for (auto k : map[arr[j]]) {
                        if (k != j) {
                            if (k == n - 1)
                                return step;
                            q.push(k);
                        }
                    }
                }
                map.erase(arr[j]);
            }
        }
        return step;
    }
};
