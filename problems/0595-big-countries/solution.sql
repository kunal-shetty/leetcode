-- 595. Big Countries
-- Difficulty: Easy
-- https://leetcode.com/problems/big-countries/
-- Runtime: 408 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-11

# Write your MySQL query statement below

SELECT name, population, area
FROM World
WHERE area >= 3000000 OR population >= 25000000
