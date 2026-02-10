# 178. Rank Scores

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/rank-scores/) ![Medium](https://img.shields.io/badge/Medium-yellow)

**Topics:** `Database`  
**Time spent:** —  
**First solved:** 2026-02-10 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [MySQL](./solution.sql) | 310 ms (—) | 0.0B (—) | 2026-02-10 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>Table: <code>Scores</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| score       | decimal |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table contains the score of a game. Score is a floating point value with two decimal places.
</pre>

<p>&nbsp;</p>

<p>Write a solution to find the rank of the scores. The ranking should be calculated according to the following rules:</p>

<ul>
	<li>The scores should be ranked from the highest to the lowest.</li>
	<li>If there is a tie between two scores, both should have the same ranking.</li>
	<li>After a tie, the next ranking number should be the next consecutive integer value. In other words, there should be no holes between ranks.</li>
</ul>

<p>Return the result table ordered by <code>score</code> in descending order.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> 
Scores table:
+----+-------+
| id | score |
+----+-------+
| 1  | 3.50  |
| 2  | 3.65  |
| 3  | 4.00  |
| 4  | 3.85  |
| 5  | 4.00  |
| 6  | 3.65  |
+----+-------+
<strong>Output:</strong> 
+-------+------+
| score | rank |
+-------+------+
| 4.00  | 1    |
| 4.00  | 1    |
| 3.85  | 2    |
| 3.65  | 3    |
| 3.65  | 3    |
| 3.50  | 4    |
+-------+------+
</pre>


</details>
