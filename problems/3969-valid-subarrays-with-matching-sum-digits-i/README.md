# 3969. Valid Subarrays With Matching Sum Digits I

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/valid-subarrays-with-matching-sum-digits-i/) ![Medium](https://img.shields.io/badge/Medium-yellow)

**Topics:** `Array` `Hash Table` `Sliding Window` `Enumeration` `Prefix Sum`  
**Time spent:** —  
**First solved:** 2026-06-21 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 155 ms (—) | 34.5 MB (—) | 2026-06-21 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>You are given an integer array <code>nums</code> and an integer digit <code>x</code>.</p>

<p>A <span data-keyword="subarray-nonempty"><strong>subarray</strong></span> <code>nums[l..r]</code> is considered <strong>valid</strong> if the sum of its elements satisfies both of the following conditions:</p>

<ul>
	<li>The first digit of the sum is equal to <code>x</code>.</li>
	<li>The last digit of the sum is equal to <code>x</code>.</li>
</ul>

<p>Return the number of valid subarrays.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,100,1], x = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<p>The valid subarrays are:</p>

<ul>
	<li><code>nums[0..0]</code>: <code>sum = 1</code></li>
	<li><code>nums[0..1]</code>: <code>sum = 1 + 100 = 101</code></li>
	<li><code>nums[1..2]</code>: <code>sum = 100 + 1 = 101</code></li>
	<li><code>nums[2..2]</code>: <code>sum = 1</code></li>
</ul>

<p>Thus, the answer is 4.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1], x = 2</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>The only subarray is <code>nums[0..0]</code> with a sum of 1, which does not satisfy the conditions.</p>

<p>Thus, the answer is 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 1500</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>1 &lt;= x &lt;= 9</code></li>
</ul>


</details>
