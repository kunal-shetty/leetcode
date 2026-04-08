// 3653. XOR After Range Multiplication Queries I
// Difficulty: Medium
// https://leetcode.com/problems/xor-after-range-multiplication-queries-i/
// Runtime: 55 ms (beats —)
// Memory: 158.1 MB (beats —)
// Submitted: 2026-04-08

class Solution {
    static const int mod = 1000000007;

public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        for (int i = 0; i < queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];

            for (int j = l; j <= r; j += k) {
                nums[j] = (1LL * nums[j] * v) % mod;
            }
        }

        int res = 0;
        for (int i = 0; i < nums.size(); i++) {
            res ^= nums[i];
        }

        return res;
    }
};
