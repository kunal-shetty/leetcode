// 1680. Concatenation of Consecutive Binary Numbers
// Difficulty: Medium
// https://leetcode.com/problems/concatenation-of-consecutive-binary-numbers/
// Runtime: 44 ms (beats —)
// Memory: 8 MB (beats —)
// Submitted: 2026-02-28

#define mod 1000000007
class Solution {
public:
    int concatenatedBinary(int n) {
        long long ans = 0;
        for(int i = 1; i <= n; ++i) {
            int shift = 0;
            int num = i;
            while(num){
                num >>= 1;
                ++shift;
            }
            ans=((ans << shift) % mod + i) % mod;
        }
        return (int)ans;
    }
};
