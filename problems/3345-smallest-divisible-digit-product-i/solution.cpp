// 3345. Smallest Divisible Digit Product I
// Difficulty: Easy
// https://leetcode.com/problems/smallest-divisible-digit-product-i/
// Runtime: 0 ms (beats —)
// Memory: 8.4 MB (beats —)
// Submitted: 2026-08-06

class Solution {
public:
int digitProduct(int n){
    int res = 1;
    while(n){
        res *= n % 10;
        n /= 10;
    }
    return res;
}
    int smallestNumber(int n, int t) {
        for(int i = n; i < 100; i++){
            if(digitProduct(n) % t == 0) return n;
            n++;
        }
        return n;
    }
};
