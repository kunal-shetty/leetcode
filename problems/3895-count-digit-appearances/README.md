# 3895. Count Digit Appearances

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/count-digit-appearances/) ![Medium](https://img.shields.io/badge/Medium-yellow)

**Topics:** `Array` `Math`  
**Time spent:** —  
**First solved:** 2026-04-11 · **Accepted submissions logged:** 2

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 5 ms (—) | 36.9 MB (—) | 2026-04-30 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>You are given an integer array <code>nums</code> and an integer <code>digit</code>.</p>

<p>Return the total number of times <code>digit</code> appears in the decimal representation of all elements in <code>nums</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [12,54,32,22], digit = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The digit 2 appears once in 12 and 32, and twice in 22. Thus, the total number of times digit 2 appears is 4.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,34,7], digit = 9</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>The digit 9 does not appear in the decimal representation of any element in <code>nums</code>, so the total number of times digit 9 appears is 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1000</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>6</sup>​​​​​​​</code></li>
	<li><code>0 &lt;= digit &lt;= 9</code></li>
</ul>


</details>
