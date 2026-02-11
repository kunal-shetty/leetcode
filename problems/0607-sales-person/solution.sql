-- 607. Sales Person
-- Difficulty: Easy
-- https://leetcode.com/problems/sales-person/
-- Runtime: 1495 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-11

# Write your MySQL query statement below
SELECT s.name
FROM SalesPerson s
WHERE s.name NOT IN
    (SELECT s.name
    FROM SalesPerson s
        LEFT JOIN Orders o ON s.sales_id = o.sales_id
        LEFT JOIN Company c ON o.com_id = c.com_id
    WHERE c.name = 'Red')
