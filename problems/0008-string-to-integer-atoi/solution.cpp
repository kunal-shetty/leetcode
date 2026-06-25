// 8. String to Integer (atoi)
// Difficulty: Medium
// https://leetcode.com/problems/string-to-integer-atoi/
// Runtime: 0 ms (beats —)
// Memory: 9.6 MB (beats —)
// Submitted: 2026-06-25

class Solution {
public:
    string validate(string s) {
        string res = "";
        int i = 0, n = s.size();
        
        while (i < n && s[i] == ' ') i++;
        
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            res += s[i];
            i++;
        }
        
        while (i < n && isdigit(s[i])) {
            res += s[i];
            i++;
        }
        
        return res;
    }

    int myAtoi(string s) {
        string num = validate(s);

        if (num.empty() || num == "+" || num == "-")
            return 0;

        int i = 0;
        int sign = 1;

        if (num[i] == '-') {
            sign = -1;
            i++;
        } else if (num[i] == '+') {
            i++;
        }

        long result = 0;

        while (i < num.size()) {
            int digit = num[i] - '0';

            if (result > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }

            result = result * 10 + digit;
            i++;
        }

        return sign * result;
    }
};
