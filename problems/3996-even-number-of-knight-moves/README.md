# 3996. Even Number of Knight Moves

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/even-number-of-knight-moves/) ![Easy](https://img.shields.io/badge/Easy-brightgreen)

**Topics:** `Array` `Math`  
**Time spent:** —  
**First solved:** 2026-07-19 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 4 ms (—) | 49.7 MB (—) | 2026-07-19 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>You are given two integer arrays <code>start</code> and <code>target</code>, where each array is of the form <code>[x, y]</code> representing a cell on a standard 8 x 8 chessboard.</p>

<p>Return <code>true</code> if a knight can move from <code>start</code> to <code>target</code> in an <strong>even</strong> number of moves. Otherwise, return <code>false</code>.</p>

<p><strong>Note:</strong> A valid knight move consists of moving two squares in one direction and one square perpendicular to it. The figure below illustrates all eight possible moves from a cell.</p>

<p><img src="https://assets.leetcode.com/uploads/2018/10/12/knight.png" style="height: 200px; width: 200px;" /></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">start = [1,1], target = [2,2]</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<p>One possible sequence of moves is <code>(1, 1) -&gt; (3, 2) -&gt; (2, 4) -&gt; (4, 3) -&gt; (2, 2)</code>.</p>

<p>The knight reaches the target in 4 moves, which is even. Thus, the answer is <code>true</code>.</p>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">start = [4,5], target = [6,6]</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong>​​​​​​​</p>

<p>It is impossible to reach <code>target = [6, 6]</code> from <code>start = [4, 5]</code> in an even number of moves. Thus, the answer is <code>false</code>.</p>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>start.length == target.length == 2</code></li>
	<li><code>0 &lt;= start[i], target[i] &lt;= 7</code></li>
</ul>


</details>
