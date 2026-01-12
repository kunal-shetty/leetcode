# 58. Length of Last Word
# Difficulty: Easy
# https://leetcode.com/problems/length-of-last-word/
# Runtime: 0 ms (beats —)
# Memory: 19.1 MB (beats —)
# Submitted: 2026-03-22

class Solution:
    def lengthOfLastWord(self, s: str) -> int:
        count = 0
        
        for ch in s[::-1]:
            if ch == ' ':
                if count > 0:
                    break
            else:
                count += 1
        
        return count
