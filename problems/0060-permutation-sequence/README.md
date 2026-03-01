# 60. Permutation Sequence

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/permutation-sequence/) ![Hard](https://img.shields.io/badge/Hard-red)

**Topics:** `Math` `Recursion`  
**Time spent:** —  
**First solved:** 2026-02-16 · **Accepted submissions logged:** 2

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 0 ms (—) | 8.8 MB (—) | 2026-03-01 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>The set <code>[1, 2, 3, ...,&nbsp;n]</code> contains a total of <code>n!</code> unique permutations.</p>

<p>By listing and labeling all of the permutations in order, we get the following sequence for <code>n = 3</code>:</p>

<ol>
	<li><code>&quot;123&quot;</code></li>
	<li><code>&quot;132&quot;</code></li>
	<li><code>&quot;213&quot;</code></li>
	<li><code>&quot;231&quot;</code></li>
	<li><code>&quot;312&quot;</code></li>
	<li><code>&quot;321&quot;</code></li>
</ol>

<p>Given <code>n</code> and <code>k</code>, return the <code>k<sup>th</sup></code> permutation sequence.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<pre><strong>Input:</strong> n = 3, k = 3
<strong>Output:</strong> "213"
</pre><p><strong class="example">Example 2:</strong></p>
<pre><strong>Input:</strong> n = 4, k = 9
<strong>Output:</strong> "2314"
</pre><p><strong class="example">Example 3:</strong></p>
<pre><strong>Input:</strong> n = 3, k = 1
<strong>Output:</strong> "123"
</pre>
<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 9</code></li>
	<li><code>1 &lt;= k &lt;= n!</code></li>
</ul>


</details>
