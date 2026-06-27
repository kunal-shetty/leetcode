// 1108. Defanging an IP Address
// Difficulty: Easy
// https://leetcode.com/problems/defanging-an-ip-address/
// Runtime: 0 ms (beats —)
// Memory: 7.8 MB (beats —)
// Submitted: 2026-06-27

class Solution {
public:
    string defangIPaddr(string address) {
        string res = "";
        for(auto a : address){
            if(a == '.') res += "[.]";
            else res += a;
        }
        return res;
    }
};
