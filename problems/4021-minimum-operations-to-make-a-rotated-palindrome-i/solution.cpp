// 4021. Minimum Operations to Make a Rotated Palindrome I
// Difficulty: Medium
// https://leetcode.com/problems/minimum-operations-to-make-a-rotated-palindrome-i/
// Runtime: 259 ms (beats —)
// Memory: 10.6 MB (beats —)
// Submitted: 2026-08-15

class Solution {
public:
    int minOperations(string s) {
        int n = s.size();
        int res = INT_MAX;
        for(int i = 0; i < n; i++){
            int c= i;
            for(int j = 0; j < n /2; j++){
                char a = s[(j + i) %n];
                char b= s[(n - 1 -j +i) %n];
                int x = (b  - a + 26) % 26;
                int y = (a -b + 26) % 26;
                
                c += min(x, y);
            }
            res = min(res, c);
        }
        return res;
    }
};
