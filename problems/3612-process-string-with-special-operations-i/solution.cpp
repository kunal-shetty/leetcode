// 3612. Process String with Special Operations I
// Difficulty: Medium
// https://leetcode.com/problems/process-string-with-special-operations-i/
// Runtime: 4 ms (beats —)
// Memory: 39.7 MB (beats —)
// Submitted: 2026-06-16

class Solution {
public:
    string processStr(string s) {
        string res = "";
        for(auto c : s){
            if(c == '*') {
                if(res.length()){
                    res.pop_back();
                }
            }
            else if(c == '#') res = res + res;
            else if(c == '%') reverse(res.begin(), res.end());
            else res += c;
        }
        return res;
    }
};
