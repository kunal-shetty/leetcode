# 2665. Counter II

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/counter-ii/) ![Easy](https://img.shields.io/badge/Easy-brightgreen)

**Topics:** —  
**Time spent:** —  
**First solved:** 2026-08-08 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [JavaScript](./solution.js) | 57 ms (—) | 54.8 MB (—) | 2026-08-08 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>Write a function&nbsp;<code>createCounter</code>. It should accept an initial integer&nbsp;<code>init</code>. It should return an object with three functions.</p>

<p>The three functions are:</p>

<ul>
	<li><code>increment()</code>&nbsp;increases&nbsp;the current value by 1 and then returns it.</li>
	<li><code>decrement()</code>&nbsp;reduces the current value by 1 and then returns it.</li>
	<li><code>reset()</code>&nbsp;sets the current value to&nbsp;<code>init</code>&nbsp;and then returns it.</li>
</ul>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<pre>
<strong>Input:</strong> init = 5, calls = [&quot;increment&quot;,&quot;reset&quot;,&quot;decrement&quot;]
<strong>Output:</strong> [6,5,4]
<strong>Explanation:</strong>
const counter = createCounter(5);
counter.increment(); // 6
counter.reset(); // 5
counter.decrement(); // 4
</pre>

<p><strong class="example">Example 2:</strong></p>

<pre>
<strong>Input:</strong> init = 0, calls = [&quot;increment&quot;,&quot;increment&quot;,&quot;decrement&quot;,&quot;reset&quot;,&quot;reset&quot;]
<strong>Output:</strong> [1,2,1,0,0]
<strong>Explanation:</strong>
const counter = createCounter(0);
counter.increment(); // 1
counter.increment(); // 2
counter.decrement(); // 1
counter.reset(); // 0
counter.reset(); // 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>-1000 &lt;= init &lt;= 1000</code></li>
	<li><code>0 &lt;= calls.length &lt;= 1000</code></li>
	<li><code>calls[i]</code> is one of &quot;increment&quot;, &quot;decrement&quot; and&nbsp;&quot;reset&quot;</li>
</ul>


</details>
