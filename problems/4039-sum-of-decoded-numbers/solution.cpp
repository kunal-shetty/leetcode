// 4039. Sum of Decoded Numbers
// Difficulty: Medium
// https://leetcode.com/problems/sum-of-decoded-numbers/
// Runtime: 127 ms (beats —)
// Memory: 91 MB (beats —)
// Submitted: 2026-08-30

class Solution {
public:
     const    int MOD = 1e9 + 7;
    
     long long modpow( long long a, long long b){
                long long res =1;
                a %= MOD;
                while(b){
                    if(b & 1) res = res * a % MOD;
                    a = a*a%MOD;
                    b >>=1;
                    
                }
                return res;
            }
    int sumDecoded(vector<long long>& nums) {
           long long res = 0;

        for(auto num : nums){
            int w = num % 10;
            long long d = num /10;
            string s = to_string(d);
            long long x = stoll(s.substr(0,w));
            long long y = stoll(s.substr(w));

                res = (res + modpow(x,y)) % MOD;
        }
        return res;
    }
};
