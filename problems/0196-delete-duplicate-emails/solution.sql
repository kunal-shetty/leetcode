-- 196. Delete Duplicate Emails
-- Difficulty: Easy
-- https://leetcode.com/problems/delete-duplicate-emails/
-- Runtime: 782 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-12

# Write your MySQL query statement below

DELETE p1 FROM Person p1
JOIN Person p2 
ON p1.email = p2.email AND p1.id > p2.id;
