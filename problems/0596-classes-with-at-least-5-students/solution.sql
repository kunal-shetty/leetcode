-- 596. Classes With at Least 5 Students
-- Difficulty: Easy
-- https://leetcode.com/problems/classes-with-at-least-5-students/
-- Runtime: 304 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-16

# Write your MySQL query statement below
SELECT class FROM Courses
GROUP BY class
HAVING COUNT(student) >= 5
