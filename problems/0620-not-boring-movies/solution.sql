-- 620. Not Boring Movies
-- Difficulty: Easy
-- https://leetcode.com/problems/not-boring-movies/
-- Runtime: 242 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-02-12

# Write your MySQL query statement below
# Write your MySQL query statement below
SELECT 
    id, 
    movie, 
    description, 
    rating
FROM 
    cinema 
WHERE 
    id % 2 != 0 
    AND description != 'boring' 
ORDER BY 
    rating DESC;
