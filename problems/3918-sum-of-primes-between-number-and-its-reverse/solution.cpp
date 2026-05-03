// 3918. Sum of Primes Between Number and Its Reverse
// Difficulty: Medium
// https://leetcode.com/problems/sum-of-primes-between-number-and-its-reverse/
// Runtime: 0 ms (beats —)
// Memory: 8.6 MB (beats —)
// Submitted: 2026-05-03

class Solution {
public:
    bool isPrime(int num){
        if(num <= 1) return false;
        for(int divisor = 2; divisor * divisor <= num; divisor++){
            if(num % divisor == 0) return false;
        }
        return true;
    }

    int reverseNumber(int num){
        int reversed = 0;
        while(num){
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
    }
    
    int sumOfPrimesInRange(int n) {
        int reversed = reverseNumber(n);
        int left = min(n, reversed);
        int right = max(n, reversed);
        int sum = 0;
        for(int i = left; i <= right; i++){
            if(isPrime(i)) sum += i;
        }

        return sum;
    }
};
