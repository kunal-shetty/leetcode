# 2667. Create Hello World Function

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/create-hello-world-function/) ![Easy](https://img.shields.io/badge/Easy-brightgreen)

**Topics:** —  
**Time spent:** —  
**First solved:** 2026-08-08 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [JavaScript](./solution.js) | 37 ms (—) | 53.8 MB (—) | 2026-08-08 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

Write a function&nbsp;<code>createHelloWorld</code>.&nbsp;It should return a new function that always returns&nbsp;<code>&quot;Hello World&quot;</code>.
<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> args = []
<strong>Output:</strong> &quot;Hello World&quot;
<strong>Explanation:</strong>
const f = createHelloWorld();
f(); // &quot;Hello World&quot;

The function returned by createHelloWorld should always return &quot;Hello World&quot;.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> args = [{},null,42]
<strong>Output:</strong> &quot;Hello World&quot;
<strong>Explanation:</strong>
const f = createHelloWorld();
f({}, null, 42); // &quot;Hello World&quot;

Any arguments could be passed to the function but it should still always return &quot;Hello World&quot;.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>0 &lt;= args.length &lt;= 10</code></li>
</ul>


</details>
