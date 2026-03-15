// 12. Integer to Roman
// Difficulty: Medium
// https://leetcode.com/problems/integer-to-roman/
// Runtime: 0 ms (beats —)
// Memory: 12 MB (beats —)
// Submitted: 2026-03-15

class Solution {
public:
    string intToRoman(int num) {
        vector<int> val = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
        vector<string> symbols = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
        
        string res = "";
        
        for(int i = 0; i < val.size(); i++){
            while(num >= val[i]){
                res += symbols[i];
                num -= val[i];
            }
        }
        
        return res;
    }
};
