// 762. Prime Number of Set Bits in Binary Representation
// Difficulty: Easy
// https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/
// Runtime: 1 ms (beats —)
// Memory: 7.8 MB (beats —)
// Submitted: 2026-02-21

class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        bool isPrime[33] = {false};
        int primes[] = {2,3,5,7,11,13,17,19,23,29,31};
        
        for(int p : primes)
            isPrime[p] = true;

        int count = 0;

        for(int i = left; i <= right; i++){
            int bits = __builtin_popcount(i);
            if(isPrime[bits]) count++;
        }

        return count;
    }
};
