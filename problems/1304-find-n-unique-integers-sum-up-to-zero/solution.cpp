// 1304. Find N Unique Integers Sum up to Zero
// Difficulty: Easy
// https://leetcode.com/problems/find-n-unique-integers-sum-up-to-zero/
// Runtime: 0 ms (beats —)
// Memory: 9.7 MB (beats —)
// Submitted: 2026-09-11

class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> res(n);
        res[0] = n * (1 - n) / 2;
        for(int i = 1; i < n; i++){
            res[i] = i;
        }
        return res;
    }
};
