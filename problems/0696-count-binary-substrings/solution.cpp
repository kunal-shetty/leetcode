// 696. Count Binary Substrings
// Difficulty: Easy
// https://leetcode.com/problems/count-binary-substrings/
// Runtime: 1 ms (beats —)
// Memory: 16.9 MB (beats —)
// Submitted: 2026-02-19

class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> res;
        int consecutive = 1;
        
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i - 1]) {
                consecutive++;
            } else {
                res.push_back(consecutive);
                consecutive = 1;
            }
        }
        
        res.push_back(consecutive);
        
        int ans = 0;
        for (int i = 1; i < res.size(); i++) {
            ans += min(res[i - 1], res[i]);
        }
        
        return ans;
    }
};
