// 4022. K-th Digit in Infinite String
// Difficulty: Medium
// https://leetcode.com/problems/k-th-digit-in-infinite-string/
// Runtime: 2 ms (beats —)
// Memory: 9.3 MB (beats —)
// Submitted: 2026-08-15

class Solution {
public:
    int kthDigit(long long k) {
        if (k <= 9)
            return k;
        k -= 9;

        long long len = 2; long long first = 1;
        while(2){
            long long blocks = 9 * first;
            long long digits = blocks * 10 * len;
            if(k > digits){
                k-=digits;
                first *= 10;
                len++;
            }
            else{
                long long idx = (k - 1) / (len * 10);
                long long pos = (k - 1) % (len * 10);

                long long b= first + idx;
                long long num;

                if(b % 2) num = b * 10 + 9 - pos/len;
                else num = b * 10 + pos /len;

                return to_string(num)[pos % len] - '0';
            }
        }
    }
};
