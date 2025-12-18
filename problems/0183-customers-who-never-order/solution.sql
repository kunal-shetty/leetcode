-- 183. Customers Who Never Order
-- Difficulty: Easy
-- https://leetcode.com/problems/customers-who-never-order/
-- Runtime: 536 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2025-12-18

# Write your MySQL query statement below
SELECT name AS Customers FROM Customers c
LEFT JOIN Orders d
ON d.customerId = c.id
WHERE d.customerId IS NULL
