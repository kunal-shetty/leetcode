-- 586. Customer Placing the Largest Number of Orders
-- Difficulty: Easy
-- https://leetcode.com/problems/customer-placing-the-largest-number-of-orders/
-- Runtime: 443 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-16

# Write your MySQL query statement below
SELECT customer_number
FROM Orders 
GROUP BY customer_number
ORDER BY COUNT(customer_number) DESC
LIMIT 1;
