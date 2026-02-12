-- 181. Employees Earning More Than Their Managers
-- Difficulty: Easy
-- https://leetcode.com/problems/employees-earning-more-than-their-managers/
-- Runtime: 638 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-12

# Write your MySQL query statement below
SELECT e.name AS Employee
FROM Employee e, Employee m
WHERE e.salary > (
    SELECT m.salary
    WHERE m.id = e.managerId
);
