// 3700. Number of ZigZag Arrays II
// Difficulty: Hard
// https://leetcode.com/problems/number-of-zigzag-arrays-ii/
// Runtime: 187 ms (beats —)
// Memory: 91.3 MB (beats —)
// Submitted: 2026-06-24

class Solution {
    static constexpr long long MOD = 1000000007LL;

    long long modPow(long long a, long long e) {
        long long r = 1;
        while (e) {
            if (e & 1) r = r * a % MOD;
            a = a * a % MOD;
            e >>= 1;
        }
        return r;
    }

    vector<long long> berlekampMassey(const vector<long long>& s) {
        vector<long long> C{1}, B{1};

        long long L = 0;
        long long m = 1;
        long long b = 1;

        for (int n = 0; n < (int)s.size(); n++) {
            long long d = 0;

            for (int i = 0; i <= L; i++) {
                d = (d + C[i] * s[n - i]) % MOD;
            }

            if (d == 0) {
                m++;
                continue;
            }

            vector<long long> T = C;

            long long coef = d * modPow(b, MOD - 2) % MOD;

            if ((int)C.size() < (int)B.size() + m) {
                C.resize(B.size() + m);
            }

            for (int i = 0; i < (int)B.size(); i++) {
                C[i + m] = (C[i + m] - coef * B[i]) % MOD;
                if (C[i + m] < 0) {
                    C[i + m] += MOD;
                }
            }

            if (2 * L <= n) {
                L = n + 1 - L;
                B = T;
                b = d;
                m = 1;
            } else {
                m++;
            }
        }

        C.erase(C.begin());

        for (auto& x : C) {
            x = (MOD - x) % MOD;
        }

        return C;
    }

    vector<long long> combine(
        const vector<long long>& a,
        const vector<long long>& b,
        const vector<long long>& rec
    ) {
        int k = rec.size();

        vector<long long> res(2 * k);

        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {
                res[i + j] =
                    (res[i + j] + a[i] * b[j]) % MOD;
            }
        }

        for (int i = 2 * k - 2; i >= k; i--) {
            for (int j = 0; j < k; j++) {
                res[i - k + j] =
                    (res[i - k + j] +
                     res[i] * rec[j]) % MOD;
            }
        }

        res.resize(k);
        return res;
    }

    long long kitamasa(
        const vector<long long>& rec,
        const vector<long long>& init,
        long long n
    ) {
        int k = rec.size();

        if (n < k) {
            return init[n];
        }

        vector<long long> pol(k), e(k);

        pol[0] = 1;

        if (k == 1) {
            e[0] = rec[0];
        } else {
            e[1] = 1;
        }

        while (n) {
            if (n & 1) {
                pol = combine(pol, e, rec);
            }

            e = combine(e, e, rec);
            n >>= 1;
        }

        long long ans = 0;

        for (int i = 0; i < k; i++) {
            ans = (ans + pol[i] * init[i]) % MOD;
        }

        return ans;
    }

    vector<long long> zigZagArraysInit(int l, int r) {
        int m = r - l + 1;

        const int TERMS = 350;

        vector<long long> seq;

        seq.push_back(m);
        seq.push_back(1LL * m * (m - 1) % MOD);

        vector<long long> down(m), up(m);

        for (int v = 0; v < m; v++) {
            down[v] = m - 1 - v;
            up[v] = v;
        }

        for (int len = 3; len <= TERMS; len++) {
            vector<long long> prefDown(m + 1);
            vector<long long> prefUp(m + 1);

            for (int i = 0; i < m; i++) {
                prefDown[i + 1] =
                    (prefDown[i] + down[i]) % MOD;

                prefUp[i + 1] =
                    (prefUp[i] + up[i]) % MOD;
            }

            vector<long long> nd(m);
            vector<long long> nu(m);

            for (int v = 0; v < m; v++) {
                nu[v] = prefDown[v];

                nd[v] =
                    (prefUp[m] -
                     prefUp[v + 1] +
                     MOD) % MOD;
            }

            down.swap(nd);
            up.swap(nu);

            long long total = 0;

            for (int i = 0; i < m; i++) {
                total = (total + down[i] + up[i]) % MOD;
            }

            seq.push_back(total);
        }

        return seq;
    }

public:
    int zigZagArrays(int n, int l, int r) {
        vector<long long> arr = zigZagArraysInit(l, r);

        if (n - 1 < (int)arr.size()) {
            return (int)arr[n - 1];
        }

        vector<long long> rec = berlekampMassey(arr);

        reverse(rec.begin(), rec.end());

        return (int)kitamasa(rec, arr, n - 1);
    }
};
