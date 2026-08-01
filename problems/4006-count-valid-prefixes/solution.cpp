// 4006. Count Valid Prefixes
// Difficulty: Easy
// https://leetcode.com/problems/count-valid-prefixes/
// Runtime: 0 ms (beats —)
// Memory: 9.4 MB (beats —)
// Submitted: 2026-08-01

class Solution {
public:
    int countValidPrefixes(string s) {
        int zero = 0, one = 0, ans = 0;
        for(auto c: s){
            if(c == '0') zero++;
            else one++;

            if(abs(zero - one) <= 1) ans++;
        }
        return ans;
    }
};
