// 2615. Sum of Distances
// Difficulty: Medium
// https://leetcode.com/problems/sum-of-distances/
// Runtime: 107 ms (beats —)
// Memory: 129.7 MB (beats —)
// Submitted: 2026-04-23

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long> res(n, 0);

        unordered_map<int, vector<int>> map;

        for (int i = 0; i < n; i++) {
            map[nums[i]].push_back(i);
        }

        for (auto it : map) {
            vector<int> pos = it.second;
            int k = pos.size();

            vector<long long> prefix(k, 0);
            prefix[0] = pos[0];

            for (int i = 1; i < k; i++) {
                prefix[i] = prefix[i - 1] + pos[i];
            }

            for (int j = 0; j < k; j++) {
                long long left = 0, right = 0;

                if (j > 0)
                    left = (long long)j * pos[j] - prefix[j - 1];

                if (j < k - 1)
                    right = (prefix[k - 1] - prefix[j]) -
                            (long long)(k - j - 1) * pos[j];

                res[pos[j]] = left + right;
            }
        }

        return res;
    }
};
