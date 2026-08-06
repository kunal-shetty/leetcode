// 925. Long Pressed Name
// Difficulty: Easy
// https://leetcode.com/problems/long-pressed-name/
// Runtime: 0 ms (beats —)
// Memory: 8.5 MB (beats —)
// Submitted: 2026-08-06

class Solution {
public:
        bool isLongPressedName(string name, string typed) {
        int i = 0, m = name.length(), n = typed.length();
        for (int j = 0; j < n; ++j)
            if (i < m && name[i] == typed[j])
                ++i;
            else if (!j || typed[j] != typed[j - 1])
                return false;
        return i == m;
    }
};
