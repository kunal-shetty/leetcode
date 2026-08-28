// 3734. Lexicographically Smallest Palindromic Permutation Greater Than Target
// Difficulty: Hard
// https://leetcode.com/problems/lexicographically-smallest-palindromic-permutation-greater-than-target/
// Runtime: 237 ms (beats —)
// Memory: 148.5 MB (beats —)
// Submitted: 2026-08-28

class Solution {
public:
    string buildPalindrome(int n, vector<int> count, string left, char& mid,
                           string& target) {
        for (int i = 25; i >= 0; i--) {
            while (count[i]) {
                left += (char)('a' + i);
                count[i]--;
            }
        }

        if (mid != '#') {
            string right = left;
            left += mid;
            reverse(right.begin(), right.end());
            left.append(right.begin(), right.end());
        } else {
            string right = left;
            reverse(right.begin(), right.end());
            left.append(right.begin(), right.end());
        }

        return left > target ? left : "";
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        vector<int> count(26, 0);

        if (n == 1) {
            return s > target ? s : "";
        }

        for (char c : s)
            count[c - 'a']++;

        char mid = '#';
        int oddCount = 0;

        for (int i = 0; i < 26; i++) {
            if (count[i] % 2) {
                mid = (char)('a' + i);
                count[i]--;
                oddCount++;
            }

            count[i] /= 2;

            if (oddCount >= 2)
                return "";
        }

        n /= 2;
        string result = "", prefix = "";

        for (int i = 0; i < n; i++) {
            string cur = prefix;
            bool found = false;

            for (int j = 0; j < 26; j++) {
                if (count[j]) {
                    count[j]--;
                    cur += (char)('a' + j);

                    string tmp = buildPalindrome(n, count, cur, mid, target);

                    if (tmp != "") {
                        prefix = cur;
                        found = true;

                        result = result == "" ? tmp : min(result, tmp);
                        break;
                    }

                    count[j]++;
                    cur.pop_back();
                }
            }

            if (!found)
                return "";
        }

        return result;
    }
};
