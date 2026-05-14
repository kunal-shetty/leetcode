-- 3793. Find Users with High Token Usage
-- Difficulty: Easy
-- https://leetcode.com/problems/find-users-with-high-token-usage/
-- Runtime: 337 ms (beats —)
-- Memory: 0.0B (beats —)
-- Submitted: 2026-05-14

# Write your MySQL query statement below

SELECT 
    user_id,
    COUNT(*) AS prompt_count,
    ROUND(AVG(tokens), 2) AS avg_tokens
FROM prompts
GROUP BY user_id
HAVING COUNT(*) >= 3
AND MAX(tokens) > AVG(tokens)
ORDER BY avg_tokens DESC, user_id ASC;
