# 1. Two Sum
# Difficulty: Easy
# https://leetcode.com/problems/two-sum/
# Runtime: 3493 ms (beats —)
# Memory: 19.8 MB (beats —)
# Submitted: 2026-03-21

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(len(nums)):
                if(nums[i] + nums[j] == target and i != j):
                    return [i, j]
        return []
