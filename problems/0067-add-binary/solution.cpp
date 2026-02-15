// 67. Add Binary
// Difficulty: Easy
// https://leetcode.com/problems/add-binary/
// Runtime: 0 ms (beats —)
// Memory: 11 MB (beats —)
// Submitted: 2026-02-15

class Solution {
public:
    string addBinary(string a, string b) {

        string result = "";
        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry) {
            int sum = carry;

            if (i >= 0) sum += a[i--] - '0';
            if (j >= 0) sum += b[j--] - '0';

            result = char((sum % 2) + '0') + result;
            carry = sum / 2;
        }

        return result;
    }
};
