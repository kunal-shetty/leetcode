# 217. Contains Duplicate
# Difficulty: Easy
# https://leetcode.com/problems/contains-duplicate/
# Runtime: 19 ms (beats —)
# Memory: 25.9 MB (beats —)
# Submitted: 2026-04-25

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        return len(nums) != len(list(set(nums)))
        
