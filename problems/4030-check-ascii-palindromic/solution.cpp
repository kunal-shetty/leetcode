// 4030. Check ASCII Palindromic
// Difficulty: Easy
// https://leetcode.com/problems/check-ascii-palindromic/
// Runtime: 4 ms (beats —)
// Memory: 9.3 MB (beats —)
// Submitted: 2026-08-23

class Solution {
public:
    bool isPalindromic(string s) {
        string b;
        for(auto c : s){
            b += bitset<8>(c).to_string();
        
        
        }
        for(int i = 0; i < b.size(); i++){
            if(b[i] != b[b.size() - 1 - i]) return false;
        }
        return true;
    }
};
