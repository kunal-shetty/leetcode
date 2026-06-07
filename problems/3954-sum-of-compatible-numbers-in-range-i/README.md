# 3954. Sum of Compatible Numbers in Range I

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/sum-of-compatible-numbers-in-range-i/) ![Easy](https://img.shields.io/badge/Easy-brightgreen)

**Topics:** `Dynamic Programming` `Bit Manipulation` `Enumeration`  
**Time spent:** —  
**First solved:** 2026-06-07 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 0 ms (—) | 8.7 MB (—) | 2026-06-07 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>You are given two integers <code>n</code> and <code>k</code>.</p>

<p>A <strong>positive</strong> integer <code>x</code> is called <strong>compatible</strong> if it satisfies both of the following conditions:</p>

<ul>
    <li><code>abs(n - x) &lt;= k</code></li>
    <li><code>(n &amp; x) == 0</code></li>
</ul>

<p>Return the sum of all <strong>compatible</strong> integers <code>x</code>.</p>

<p><strong>Note</strong>:</p>

<ul>
    <li>Here, <code>&amp;</code> denotes the <strong>bitwise AND</strong> operator.</li>
    <li>The <strong>absolute</strong> difference between integers <code>i</code> and <code>j</code> is defined as <code>abs(i - j)</code>.</li>
</ul>
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 2, k = 3</span></p>

<p><strong>Output:</strong> <span class="example-io">10</span></p>

<p><strong>Explanation:</strong></p>

<p>The compatible integers are:</p>

<ul>
	<li><code>x = 1</code>, since <code>abs(2 - 1) = 1</code> and <code>2 &amp; 1 = 0</code>.</li>
	<li><code>x = 4</code>, since <code>abs(2 - 4) = 2</code> and <code>2 &amp; 4 = 0</code>.</li>
	<li><code>x = 5</code>, since <code>abs(2 - 5) = 3</code> and <code>2 &amp; 5 = 0</code>.</li>
</ul>

<p>Thus, the answer is <code>1 + 4 + 5 = 10</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5, k = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">0</span></p>

<p><strong>Explanation:</strong></p>

<p>There are no compatible integers in the range <code>[4, 6]</code>. Thus, the answer is 0.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 100</code></li>
	<li><code>1 &lt;= k &lt;= 100</code></li>
</ul>


</details>
