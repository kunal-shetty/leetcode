// 1415. The k-th Lexicographical String of All Happy Strings of Length n
// Difficulty: Medium
// https://leetcode.com/problems/the-k-th-lexicographical-string-of-all-happy-strings-of-length-n/
// Runtime: 0 ms (beats —)
// Memory: 8 MB (beats —)
// Submitted: 2026-03-14

class Solution {
public:
    string getHappyString(int n, int k) {
        int total = 3 << (n - 1);
        if (k > total) return "";

        int base = 1 << (n - 1);
        int first = (k - 1) / base;
        int rem = (k - 1) % base;

        string res(n, ' ');
        res[0] = 'a' + first;

        const char next[3][2] = {
            {'b','c'},
            {'a','c'},
            {'a','b'}
        };

        for (int i = 1; i < n; i++) {
            int prev = res[i - 1] - 'a';
            int bit = (rem >> (n - 1 - i)) & 1;
            res[i] = next[prev][bit];
        }

        return res;
    }
};
