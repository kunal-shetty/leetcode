# 575. Distribute Candies
# Difficulty: Easy
# https://leetcode.com/problems/distribute-candies/
# Runtime: 23 ms (beats —)
# Memory: 21.2 MB (beats —)
# Submitted: 2026-05-12

class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        return min(len(candyType) // 2, len(set(candyType)))
        
