# 9. Palindrome Number
# Difficulty: Easy
# https://leetcode.com/problems/palindrome-number/
# Runtime: 6 ms (beats —)
# Memory: 19.2 MB (beats —)
# Submitted: 2026-03-21

class Solution:
    def isPalindrome(self, x: int) -> bool:
        rev, n = 0, x
        while(x > 0):
            rem = x % 10
            rev = rev * 10 + rem
            x //= 10
        return n == rev
