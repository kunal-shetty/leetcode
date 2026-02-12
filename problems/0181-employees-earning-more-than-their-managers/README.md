# 181. Employees Earning More Than Their Managers

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/employees-earning-more-than-their-managers/) ![Easy](https://img.shields.io/badge/Easy-brightgreen)

**Topics:** `Database`  
**Time spent:** —  
**First solved:** 2026-02-12 · **Accepted submissions logged:** 2

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [MySQL](./solution.sql) | 638 ms (—) | 0.0B (—) | 2026-02-12 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>Table: <code>Employee</code></p>

<pre>
+-------------+---------+
| Column Name | Type    |
+-------------+---------+
| id          | int     |
| name        | varchar |
| salary      | int     |
| managerId   | int     |
+-------------+---------+
id is the primary key (column with unique values) for this table.
Each row of this table indicates the ID of an employee, their name, salary, and the ID of their manager.
</pre>

<p>&nbsp;</p>

<p>Write a solution&nbsp;to find the employees who earn more than their managers.</p>

<p>Return the result table in <strong>any order</strong>.</p>

<p>The result format is in the following example.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> 
Employee table:
+----+-------+--------+-----------+
| id | name  | salary | managerId |
+----+-------+--------+-----------+
| 1  | Joe   | 70000  | 3         |
| 2  | Henry | 80000  | 4         |
| 3  | Sam   | 60000  | Null      |
| 4  | Max   | 90000  | Null      |
+----+-------+--------+-----------+
<strong>Output:</strong> 
+----------+
| Employee |
+----------+
| Joe      |
+----------+
<strong>Explanation:</strong> Joe is the only employee who earns more than his manager.
</pre>


</details>
