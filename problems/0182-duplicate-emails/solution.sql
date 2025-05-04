-- 182. Duplicate Emails
-- Difficulty: Easy
-- https://leetcode.com/problems/duplicate-emails/
-- Runtime: 368 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2025-05-04

# Write your MySQL query statement below
SELECT email FROM Person 
GROUP BY email
HAVING COUNT(email) > 1
