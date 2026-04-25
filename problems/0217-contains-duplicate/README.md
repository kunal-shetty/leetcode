# 217. Contains Duplicate

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/contains-duplicate/) ![Easy](https://img.shields.io/badge/Easy-brightgreen)

**Topics:** `Array` `Hash Table` `Sorting`  
**Time spent:** —  
**First solved:** 2026-03-01 · **Accepted submissions logged:** 3

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 91 ms (—) | 113.3 MB (—) | 2026-08-31 |
| [Python](./solution.py) | 19 ms (—) | 25.9 MB (—) | 2026-04-25 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>Given an integer array <code>nums</code>, return <code>true</code> if any value appears <strong>at least twice</strong> in the array, and return <code>false</code> if every element is distinct.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,1]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>The element 1 occurs at the indices 0 and 3.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,2,3,4]</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<p>All elements are distinct.</p>
</div>

<p><strong class="example">Example 3:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1,3,3,4,3,2,4,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 10<sup>5</sup></code></li>
	<li><code>-10<sup>9</sup> &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
</ul>


</details>
