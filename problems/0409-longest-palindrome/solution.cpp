// 409. Longest Palindrome
// Difficulty: Easy
// https://leetcode.com/problems/longest-palindrome/
// Runtime: 0 ms (beats —)
// Memory: 9.4 MB (beats —)
// Submitted: 2026-06-16

class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> odd;
        int oddCount = 0;
        for(auto c : s){
            odd[c]++;
            if(odd[c] % 2) oddCount++;
            else oddCount--;
        }
        if(oddCount > 0){
            return s.length() - oddCount + 1;
        }
        return s.length();
    }
};
