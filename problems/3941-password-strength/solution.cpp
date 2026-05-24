// 3941. Password Strength
// Difficulty: Medium
// https://leetcode.com/problems/password-strength/
// Runtime: 15 ms (beats —)
// Memory: 17.5 MB (beats —)
// Submitted: 2026-05-24

class Solution {
public:
    int passwordStrength(string password) {
        int s = 0;
        unordered_set<char> set;
        for (char ch : password) {
            set.insert(ch);
        }
        for (char ch : set) {
            if (ch >= 'a' && ch <= 'z')
                s += 1;
            else if (ch >= 'A' && ch <= 'Z')
                s += 2;
            else if (ch >= '0' && ch <= '9')
                s += 3;
            else
                s += 5;
        }
        return s;
    }
};
