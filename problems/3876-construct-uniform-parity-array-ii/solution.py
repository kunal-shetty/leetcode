# 3876. Construct Uniform Parity Array II
# Difficulty: Medium
# https://leetcode.com/problems/construct-uniform-parity-array-ii/
# Runtime: 71 ms (beats —)
# Memory: 35.9 MB (beats —)
# Submitted: 2026-03-22

class Solution:
    def uniformArray(self, nums1: list[int]) -> bool:
        odds = [x for x in nums1 if x % 2 == 1]
        evens = [x for x in nums1 if x % 2 == 0]

        if not odds:
            return True

        min_odd = min(odds)

        for e in evens:
            if e <= min_odd:
                return False

        return True
