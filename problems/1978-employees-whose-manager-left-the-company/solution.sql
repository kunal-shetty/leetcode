-- 1978. Employees Whose Manager Left the Company
-- Difficulty: Easy
-- https://leetcode.com/problems/employees-whose-manager-left-the-company/
-- Runtime: 315 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-16

# Write your MySQL query statement below
SELECT employee_id 
FROM Employees
WHERE salary < 30000 AND
manager_id NOT IN (SELECT employee_id  FROM Employees)
ORDER BY employee_id
