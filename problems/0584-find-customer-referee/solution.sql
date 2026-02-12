-- 584. Find Customer Referee
-- Difficulty: Easy
-- https://leetcode.com/problems/find-customer-referee/
-- Runtime: 463 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-12

# Write your MySQL query statement below
SELECT name 
FROM Customer
WHERE referee_id != 2 OR referee_id IS null
