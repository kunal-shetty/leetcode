# 3658. GCD of Odd and Even Sums

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/gcd-of-odd-and-even-sums/) ![Easy](https://img.shields.io/badge/Easy-brightgreen)

**Topics:** `Math` `Number Theory`  
**Time spent:** —  
**First solved:** 2026-07-15 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 2 ms (—) | 8.6 MB (—) | 2026-07-15 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>You are given an integer <code>n</code>. Your task is to compute the <strong>GCD</strong> (greatest common divisor) of two values:</p>

<ul>
	<li>
	<p><code>sumOdd</code>: the sum of the smallest&nbsp;<code>n</code>&nbsp;positive odd numbers.</p>
	</li>
	<li>
	<p><code>sumEven</code>: the sum of the smallest&nbsp;<code>n</code>&nbsp;positive even numbers.</p>
	</li>
</ul>

<p>Return the GCD of <code>sumOdd</code> and <code>sumEven</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 4</span></p>

<p><strong>Output:</strong> <span class="example-io">4</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Sum of the first 4 odd numbers <code>sumOdd = 1 + 3 + 5 + 7 = 16</code></li>
	<li>Sum of the first 4 even numbers <code>sumEven = 2 + 4 + 6 + 8 = 20</code></li>
</ul>

<p>Hence, <code>GCD(sumOdd, sumEven) = GCD(16, 20) = 4</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">n = 5</span></p>

<p><strong>Output:</strong> <span class="example-io">5</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Sum of the first 5 odd numbers <code>sumOdd = 1 + 3 + 5 + 7 + 9 = 25</code></li>
	<li>Sum of the first 5 even numbers <code>sumEven = 2 + 4 + 6 + 8 + 10 = 30</code></li>
</ul>

<p>Hence, <code>GCD(sumOdd, sumEven) = GCD(25, 30) = 5</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= n &lt;= 10​​​​​​​00</code></li>
</ul>


</details>
