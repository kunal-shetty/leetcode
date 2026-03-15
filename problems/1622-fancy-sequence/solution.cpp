// 1622. Fancy Sequence
// Difficulty: Hard
// https://leetcode.com/problems/fancy-sequence/
// Runtime: 77 ms (beats —)
// Memory: 192.4 MB (beats —)
// Submitted: 2026-03-15

class Fancy {
public:
    vector<long long> arr;
    long long add = 0, mul = 1;
    const long long MOD = 1000000007;

    Fancy() {}

    void append(int val) {
        long long x = (val - add + MOD) % MOD;

        long long base = mul, exp = MOD - 2, inv = 1;
        while (exp) {
            if (exp & 1) inv = (inv * base) % MOD;
            base = (base * base) % MOD;
            exp >>= 1;
        }

        x = (x * inv) % MOD;
        arr.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        mul = (mul * m) % MOD;
        add = (add * m) % MOD;
    }
    
    int getIndex(int idx) {
        if (idx >= arr.size()) return -1;
        return (arr[idx] * mul + add) % MOD;
    }
};
