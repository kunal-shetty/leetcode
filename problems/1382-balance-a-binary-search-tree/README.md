# 1382. Balance a Binary Search Tree

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/balance-a-binary-search-tree/) ![Medium](https://img.shields.io/badge/Medium-yellow)

**Topics:** `Divide and Conquer` `Greedy` `Tree` `Depth-First Search` `Binary Search Tree` `Binary Tree`  
**Time spent:** —  
**First solved:** 2026-02-09 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 24 ms (—) | 65.7 MB (—) | 2026-02-09 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>Given the <code>root</code> of a binary search tree, return <em>a <strong>balanced</strong> binary search tree with the same node values</em>. If there is more than one answer, return <strong>any of them</strong>.</p>

<p>A binary search tree is <strong>balanced</strong> if the depth of the two subtrees of every node never differs by more than <code>1</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/balance1-tree.jpg" style="width: 500px; height: 319px;" />
<pre>
<strong>Input:</strong> root = [1,null,2,null,3,null,4,null,null]
<strong>Output:</strong> [2,1,3,null,null,null,4]
<b>Explanation:</b> This is not the only correct answer, [3,1,4,null,2] is also correct.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2021/08/10/balanced2-tree.jpg" style="width: 224px; height: 145px;" />
<pre>
<strong>Input:</strong> root = [2,1,3]
<strong>Output:</strong> [2,1,3]
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li>The number of nodes in the tree is in the range <code>[1, 10<sup>4</sup>]</code>.</li>
	<li><code>1 &lt;= Node.val &lt;= 10<sup>5</sup></code></li>
</ul>


</details>
