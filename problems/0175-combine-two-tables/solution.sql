-- 175. Combine Two Tables
-- Difficulty: Easy
-- https://leetcode.com/problems/combine-two-tables/
-- Runtime: 1458 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-12

# Write your MySQL query statement below
SELECT p.firstName, p.lastName, a.city, a.state
FROM Person AS p
LEFT JOIN Address AS a
ON p.personId = a.personId
