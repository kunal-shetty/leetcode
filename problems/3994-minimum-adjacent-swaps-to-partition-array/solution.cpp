// 3994. Minimum Adjacent Swaps to Partition Array
// Difficulty: Medium
// https://leetcode.com/problems/minimum-adjacent-swaps-to-partition-array/
// Runtime: 7 ms (beats —)
// Memory: 164.3 MB (beats —)
// Submitted: 2026-07-18

class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        const int MOD = 1e9 + 7;
        vector<int> rank;
        for (auto num : nums) {
            if (num < a)
                rank.push_back(0);
            else if (num <= b)
                rank.push_back(1);
            else
                rank.push_back(2);
        }
        vector<long long> bit(4, 0);
        long long ans = 0, seen = 0;

        for (auto r : rank) {
            ans += seen - query(bit, r);
            seen++;
            update(bit, r);
        }
        return ans % MOD;
    }
    void update(vector<long long>& bit, int idx) {
        idx++;
        while (idx <= 3) {
            bit[idx]++;
            idx += idx & -idx;
        }
    }
    long long query(vector<long long>& bit, int idx) {
        idx++;
        long long sum = 0;
        while (idx > 0) {
            sum += bit[idx];
            idx -= idx & -idx;
        }
        return sum;
    }
};
