// 3922. Minimum Flips to Make Binary String Coherent
// Difficulty: Medium
// https://leetcode.com/problems/minimum-flips-to-make-binary-string-coherent/
// Runtime: 15 ms (beats —)
// Memory: 19.7 MB (beats —)
// Submitted: 2026-05-09

class Solution {
public:
    int minFlips(string s) {
        int n = s.size();
        
        int ones = 0;
        for(char c : s) {
            if(c == '1') ones++;
        }
        
        int ans = n;
        
        ans = min(ans, ones);
        ans = min(ans, n - ones);
        
        if(ones > 0)
            ans = min(ans, ones - 1);
        else
            ans = min(ans, 1);
        
        if(n >= 2) {
            int cost = 0;
            
            if(s[0] == '0') cost++;
            if(s[n - 1] == '0') cost++;
            
            for(int i = 1; i < n - 1; i++) {
                if(s[i] == '1') cost++;
            }
            
            ans = min(ans, cost);
        }
        
        return ans;
    }
};
