// 4079. Prime Subset Selection I
// Difficulty: Medium
// https://leetcode.com/problems/prime-subset-selection-i/
// Runtime: 344 ms (beats —)
// Memory: 67.3 MB (beats —)
// Submitted: 2026-10-11

class Solution {
public:
    vector<int> maxPrimes(int n, int s) {
        vector<bool> prime(n + 1, true);
        prime[0] = prime[1] = false;
        for(int i = 2; i *i<=n; i++){
            if(prime[i]){
                for(int j = i *i; j <= n; j+=i) prime[j]  = false;
            }
        }
        vector<int> res;
        for(int i =2; i<=n;i++){
            if(prime[i] && i <= s){
                res.push_back(i);
                s -=i;
            }
        }
        return res;
    }
};
