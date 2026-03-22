-- 511. Game Play Analysis I
-- Difficulty: Easy
-- https://leetcode.com/problems/game-play-analysis-i/
-- Runtime: 510 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-03-22

# Write your MySQL query statement below
SELECT player_id, MIN(event_date) AS first_login
FROM Activity
GROUP BY player_id;
