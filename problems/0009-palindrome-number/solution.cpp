// 9. Palindrome Number
// Difficulty: Easy
// https://leetcode.com/problems/palindrome-number/
// Runtime: 4 ms (beats —)
// Memory: 10.8 MB (beats —)
// Submitted: 2026-07-18

class Solution {
public:
    bool isPalindrome(int x) {
       if(x < 0) return false;
        string s = to_string(x);
        int left = 0, right = s.length() - 1;
        while(left <= right){
            if(s[left] != s[right]) return false;
            left++; right--;
        }
        return true;
    }
};
