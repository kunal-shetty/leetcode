# 3827. Count Monobit Integers

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/count-monobit-integers/) ![Easy](https://img.shields.io/badge/Easy-brightgreen)

**Topics:** `Bit Manipulation` `Enumeration`  
**Time spent:** —  
**First solved:** 2026-04-24 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 0 ms (—) | 8.6 MB (—) | 2026-04-24 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>You are given an integer <code>n</code>.</p>

<p>An integer is called <strong>Monobit</strong> if all bits in its binary representation are the same.</p>

<p>Return the count of <strong>Monobit</strong> integers in the range <code>[0, n]</code> (inclusive).</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 1</span></p>

<p><strong>Output:</strong> <span class="example-io">2</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The integers in the range <code>[0, 1]</code> have binary representations <code>&quot;0&quot;</code> and <code>&quot;1&quot;</code>.</li>
	<li>Each representation consists of identical bits. Thus, the answer is 2.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">3</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The integers in the range <code>[0, 4]</code> include binaries <code>&quot;0&quot;</code>, <code>&quot;1&quot;</code>, <code>&quot;10&quot;</code>, <code>&quot;11&quot;</code>, and <code>&quot;100&quot;</code>.</li>
	<li>Only 0, 1 and 3 satisfy the Monobit condition. Thus, the answer is 3.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= n &lt;= 1000</code></li>
</ul>


</details>
