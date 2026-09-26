// 4062. Transform Array Using Pair Operations
// Difficulty: Medium
// https://leetcode.com/problems/transform-array-using-pair-operations/
// Runtime: 0 ms (beats —)
// Memory: 193.2 MB (beats —)
// Submitted: 2026-09-26

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

class Solution {
public:
    bool canTransform(vector<int>& source, vector<int>& target) {
        ll s = 0, t = 0;
        for (auto i : source) s += i;
        for (auto i : target) t += i;
        return s == t;
    }
};
