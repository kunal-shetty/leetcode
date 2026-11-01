// 4462. minimize the maximum value of gcd connected array
// Difficulty: Unknown
// https://leetcode.com/problems/minimize-the-maximum-value-of-gcd-connected-array/
// Runtime: 5 ms (beats 27.3%)
// Memory: 8.8 MB (beats 100.0%)
// Submitted: 2026-11-01

class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if(value == 1) return -1;
        int p = value;
        for(int i = 2; 1LL *i * i <= value; i++){
            if(value % i == 0) {p  =i; break;}
        }
        if(2LL *index  > value - p) return -1;
        int r = n - index- 1;
        if(r== 0) return value;
        long long res = 1LL *(value + p);
        res += 2 * (r - 1);

        return res;
    }
};
