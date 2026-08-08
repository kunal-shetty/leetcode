# 2704. To Be Or Not To Be

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/to-be-or-not-to-be/) ![Easy](https://img.shields.io/badge/Easy-brightgreen)

**Topics:** —  
**Time spent:** —  
**First solved:** 2026-08-08 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [JavaScript](./solution.js) | 50 ms (—) | 52.6 MB (—) | 2026-08-08 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>Write a function&nbsp;<code>expect</code> that helps developers test their code. It should take in any value&nbsp;<code>val</code>&nbsp;and return an object with the following two functions.</p>

<ul>
	<li><code>toBe(val)</code>&nbsp;accepts another value and returns&nbsp;<code>true</code>&nbsp;if the two values&nbsp;<code>===</code>&nbsp;each other. If they are not equal, it should throw an error&nbsp;<code>&quot;Not Equal&quot;</code>.</li>
	<li><code>notToBe(val)</code>&nbsp;accepts another value and returns&nbsp;<code>true</code>&nbsp;if the two values&nbsp;<code>!==</code>&nbsp;each other. If they are equal, it should throw an error&nbsp;<code>&quot;Equal&quot;</code>.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> func = () =&gt; expect(5).toBe(5)
<strong>Output:</strong> {&quot;value&quot;: true}
<strong>Explanation:</strong> 5 === 5 so this expression returns true.
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> func = () =&gt; expect(5).toBe(null)
<strong>Output:</strong> {&quot;error&quot;: &quot;Not Equal&quot;}
<strong>Explanation:</strong> 5 !== null so this expression throw the error &quot;Not Equal&quot;.
</pre>

<p><strong class="example">Example 3:</strong></p>

<pre>
<strong>Input:</strong> func = () =&gt; expect(5).notToBe(null)
<strong>Output:</strong> {&quot;value&quot;: true}
<strong>Explanation:</strong> 5 !== null so this expression returns true.
</pre>


</details>
