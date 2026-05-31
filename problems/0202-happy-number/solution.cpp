// 202. Happy Number
// Difficulty: Easy
// https://leetcode.com/problems/happy-number/
// Runtime: 2 ms (beats —)
// Memory: 8.4 MB (beats —)
// Submitted: 2026-05-31

class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> seen;
        while(n != 1){
            int res = 0;
            while(n){
                res += (n % 10) * (n % 10);
                n /= 10;
            }
            if(seen.contains(res)) return false;
            seen.insert(res);
            n = res;
        }
        return true;
    }
};
