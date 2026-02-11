-- 577. Employee Bonus
-- Difficulty: Easy
-- https://leetcode.com/problems/employee-bonus/
-- Runtime: 1055 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-11

# Write your MySQL query statement below
SELECT e.name, b.bonus 
FROM Employee e 
LEFT JOIN Bonus b 
ON e.empId = b.empId
WHERE bonus < 1000 OR bonus IS null
