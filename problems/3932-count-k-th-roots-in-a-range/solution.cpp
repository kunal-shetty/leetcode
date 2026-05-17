// 3932. Count K-th Roots in a Range
// Difficulty: Medium
// https://leetcode.com/problems/count-k-th-roots-in-a-range/
// Runtime: 0 ms (beats —)
// Memory: 8.7 MB (beats —)
// Submitted: 2026-05-17

class Solution {
public:
    long long power(long long a, int k, long long limit){
        long long res = 1;
        for(int i = 0; i < k; i++){
            if(a != 0 && res > limit / a){
                return limit + 1;
            }
            res *= a;
        }
        return res;
    }
    int count(long long n, int k){
        long long l = 0, r = 1e9;
        long long ans = -1;
        while(l <= r){
            long long mid = (l + r) / 2;
            if(power(mid, k, n) <= n){
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans + 1;
    }
    int countKthRoots(int l, int r, int k) {
        return count(r, k) - count((long long)l - 1, k);
    }
};
