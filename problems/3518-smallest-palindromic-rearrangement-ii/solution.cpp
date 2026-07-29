// 3518. Smallest Palindromic Rearrangement II
// Difficulty: Hard
// https://leetcode.com/problems/smallest-palindromic-rearrangement-ii/
// Runtime: 17 ms (beats —)
// Memory: 17.1 MB (beats —)
// Submitted: 2026-07-29

class Solution {
public:
    long long nCr(long long n, long long r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        long long ans = 1;
        for (long long i = 1; i <= r; i++) {
            ans = ans * (n - r + i) / i;
            if (ans > 1000000) return 1000001;
        }
        return ans;
    }

    long long ways(vector<int>& cnt, int rem) {
        long long ans = 1;
        for (int x : cnt) {
            if (!x) continue;
            ans *= nCr(rem, x);
            if (ans > 1000000) return 1000001;
            rem -= x;
        }
        return ans;
    }

    string smallestPalindrome(string s, int k) {
        vector<int> f(26), half(26);
        for (char c : s) f[c - 'a']++;

        char mid = 0;
        int rem = 0;

        for (int i = 0; i < 26; i++) {
            half[i] = f[i] / 2;
            rem += half[i];
            if (f[i] % 2) mid = 'a' + i;
        }

        if (ways(half, rem) < k) return "";

        string left;

        while (rem--) {
            for (int i = 0; i < 26; i++) {
                if (!half[i]) continue;

                half[i]--;
                long long w = ways(half, rem);

                if (w >= k) {
                    left += char('a' + i);
                    break;
                }

                k -= w;
                half[i]++;
            }
        }

        string right = left;
        reverse(right.begin(), right.end());

        return mid ? left + mid + right : left + right;
    }
};
