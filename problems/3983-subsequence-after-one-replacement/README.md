# 3983. Subsequence After One Replacement

[![LeetCode](https://img.shields.io/badge/LeetCode-open%20problem-orange?logo=leetcode)](https://leetcode.com/problems/subsequence-after-one-replacement/) ![Medium](https://img.shields.io/badge/Medium-yellow)

**Topics:** `Two Pointers` `String`  
**Time spent:** —  
**First solved:** 2026-07-05 · **Accepted submissions logged:** 1

## Submissions

| Language | Runtime (beats) | Memory (beats) | Date |
| --- | --- | --- | --- |
| [C++](./solution.cpp) | 301 ms (—) | 353.8 MB (—) | 2026-07-05 |

## Notes

<!-- notes:start -->
_No notes yet._
<!-- notes:end -->

<details>
<summary>Problem description</summary>

<p>You are given two strings <code>s</code> and <code>t</code> consisting of lowercase English letters.</p>

<p>You may choose <strong>at most</strong> one index in <code>s</code> and replace the character at that index with any lowercase English letter.</p>

<p>Return <code>true</code> if it is possible to make <code>s</code> a <span data-keyword="subsequence-string">subsequence</span> of <code>t</code>; otherwise, return <code>false</code>.</p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;cat&quot;, t = &quot;chat&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">true</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>Replace <code>s[1]</code> from <code>&#39;a&#39;</code> to <code>&#39;h&#39;</code>. The resulting string is <code>&quot;cht&quot;</code>.</li>
	<li><code>&quot;cht&quot;</code> is a subsequence of <code>&quot;chat&quot;</code> because we can match <code>&#39;c&#39;</code>, <code>&#39;h&#39;</code>, and <code>&#39;t&#39;</code> in order.</li>
</ul>
</div>

<p><strong class="example">Example 2:</strong></p>

<div class="example-block">
<p><strong>Input:</strong> <span class="example-io">s = &quot;plane&quot;, t = &quot;apple&quot;</span></p>

<p><strong>Output:</strong> <span class="example-io">false</span></p>

<p><strong>Explanation:</strong></p>

<ul>
	<li>The characters <code>&#39;p&#39;</code>, <code>&#39;l&#39;</code>, and <code>&#39;e&#39;</code> can be matched in <code>t</code>, but the remaining characters cannot be matched while preserving the required order.</li>
	<li>Even after replacing any one character in <code>s</code>, it is impossible to make <code>s</code> a subsequence of <code>t</code>.</li>
</ul>
</div>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= s.length, t.length &lt;= 10<sup>5</sup></code></li>
	<li><code>s</code> and <code>t</code> consist only of lowercase English letters.</li>
</ul>


</details>
