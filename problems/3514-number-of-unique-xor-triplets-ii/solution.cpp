// 3514. Number of Unique XOR Triplets II
// Difficulty: Medium
// https://leetcode.com/problems/number-of-unique-xor-triplets-ii/
// Runtime: 1003 ms (beats —)
// Memory: 35.8 MB (beats —)
// Submitted: 2026-07-24

class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAX = 2048;
        if(nums.size() == 1) return 1;
        vector<bool> one(MAX, false);
        vector<bool> two(MAX, false);
        vector<bool> three(MAX, false);

        for (int val : nums) {
            for (int x = 0; x < MAX; x++) {
                if (one[x])
                    two[x ^ val] = true;
            }
            one[val] = true;
        }

        for (int val : nums) {
            for (int x = 0; x < MAX; x++) {
                if (two[x])
                    three[x ^ val] = true;
            }
        }

        int ans = 0;
        for (bool exists : three)
            ans += exists;

        return ans;
    }
};
