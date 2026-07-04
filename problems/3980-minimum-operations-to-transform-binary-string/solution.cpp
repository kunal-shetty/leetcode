// 3980. Minimum Operations to Transform Binary String
// Difficulty: Medium
// https://leetcode.com/problems/minimum-operations-to-transform-binary-string/
// Runtime: 11 ms (beats —)
// Memory: 30.1 MB (beats —)
// Submitted: 2026-07-04

class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();
        if(n == 1){
            if(s1 == s2) return 0;
            if(s1[0] == '0' && s2[0] == '1') return 1;
            return -1;
        }
        long long a = 0;
        long long pairs = 0;
        long long m = 0;
        int i =0;
        while(i <n){
            if(s1[i] == '0' && s2[i] == '1'){
                a++; i++;
            }
            else  if(s1[i] == '1' && s2[i] == '0'){
                int j = i;
                while(j < n && s1[j] == '1' && s2[j] == '0') j++;
                int len = j - i;
                pairs += len  /2;
                m += len % 2;
                i = j;
            }
            else i++;
        }
        return (a + pairs + 2 * m);
    }
};
