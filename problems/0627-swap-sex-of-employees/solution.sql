-- 627. Swap Sex of Employees
-- Difficulty: Easy
-- https://leetcode.com/problems/swap-sex-of-employees/
-- Runtime: 235 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-03-27

# Write your MySQL query statement below
UPDATE Salary
SET sex = 
CASE 
    WHEN sex = 'm' THEN 'f'
    ELSE 'm'
END
