-- 610. Triangle Judgement
-- Difficulty: Easy
-- https://leetcode.com/problems/triangle-judgement/
-- Runtime: 249 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-03-27

# Write your MySQL query statement below
SELECT x, y, z, 
IF(x + y > z AND x + z > y AND y + z > x, 'Yes', 'No' ) AS triangle
FROM Triangle 
