-- 178. Rank Scores
-- Difficulty: Medium
-- https://leetcode.com/problems/rank-scores/
-- Runtime: 310 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-10

# Write your MySQL query statement below
SELECT score, DENSE_RANK() OVER (ORDER BY score DESC) as'rank'
FROM Scores 
ORDER BY score DESC;
