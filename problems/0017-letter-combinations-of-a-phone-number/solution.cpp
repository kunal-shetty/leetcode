// 17. Letter Combinations of a Phone Number
// Difficulty: Medium
// https://leetcode.com/problems/letter-combinations-of-a-phone-number/
// Runtime: 0 ms (beats —)
// Memory: 9.2 MB (beats —)
// Submitted: 2026-01-31

class Solution {
public:
    vector<string> result;

    void backtrack(string &digits, int index, string &current, char keypad[10][5]) {
        if (index == digits.length()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        for (int i = 0; keypad[digit][i] != '\0'; i++) {
            current.push_back(keypad[digit][i]);
            backtrack(digits, index + 1, current, keypad);
            current.pop_back(); 
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        char keypad[10][5] = {
            "",     // 0
            "",     // 1
            "abc",  // 2
            "def",  // 3
            "ghi",  // 4
            "jkl",  // 5
            "mno",  // 6
            "pqrs", // 7
            "tuv",  // 8
            "wxyz"  // 9
        };

        string current = "";
        backtrack(digits, 0, current, keypad);
        return result;
    }
};
