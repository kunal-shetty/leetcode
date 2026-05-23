# 3937. Minimum Operations to Make Array Modulo Alternating I

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/minimum-operations-to-make-array-modulo-alternating-i/) ![Medium](https://img.shields.io/badge/Medium-yellow)

**Topics:** `Array` `Enumeration`  
**Time spent:** —  
**First solved:** 2026-05-23 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 0 ms (—) | 24.9 MB (—) | 2026-05-23 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>You are given an integer array <code>nums</code> and an integer <code>k</code>.</p>

<p>In one operation, you can <strong>increase</strong> or <strong>decrease</strong> any element of <code>nums</code> by 1.</p>

<p>An array is called <strong>modulo alternating</strong> if there exist two <strong>distinct</strong> integers <code>x</code> and <code>y</code> (<code>0 &lt;= x, y &lt; k</code>) such that:</p>

<ul>
	<li>For every <strong>even</strong> index <code>i</code>, <code>nums[i] % k == x</code></li>
	<li>For every <strong>odd</strong> index <code>i</code>, <code>nums[i] % k == y</code></li>
</ul>

<p>Return the <strong>minimum</strong> number of operations required to make <code>nums</code> <strong>modulo alternating</strong>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,4,2,8], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Let&#39;s choose <code>x = 1</code> for even indices and <code>y = 2</code> for odd indices.</li>
	<li>Perform the following operations:
	<ul>
		<li>Increment <code>nums[1] = 4</code> by 1, giving <code>nums = [1, 5, 2, 8]</code>.</li>
		<li>Decrement <code>nums[2] = 2</code> by 1, giving <code>nums = [1, 5, 1, 8]</code>.</li>
	</ul>
	</li>
	<li>Now, for even indices, <code>nums[i] % k = 1</code>, and for odd indices, <code>nums[i] % k = 2</code>.</li>
	<li>Thus, the total number of operations required is 2.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">nums = [1,1,1], k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">1</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Incrementing <code>nums[1]</code> by 1 gives <code>nums = [1, 2, 1]</code>, which satisfies the condition with <code>x = 1</code> and <code>y = 2</code>.</li>
	<li>Thus, the total number of operations required is 1.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 100</code></li>
	<li><code>1 &lt;= nums[i] &lt;= 10<sup>9</sup></code></li>
	<li><code>2 &lt;= k &lt;= 100</code></li>
</ul>


</details>
