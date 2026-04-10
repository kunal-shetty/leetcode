// 387. First Unique Character in a String
// Difficulty: Easy
// https://leetcode.com/problems/first-unique-character-in-a-string/
// Runtime: 18 ms (beats —)
// Memory: 15 MB (beats —)
// Submitted: 2026-04-10

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, int> count;
        for(char ch : s){
            count[ch]++;
        }
        for(int i = 0; i < s.length(); i++){
            if(count[s[i]] == 1) return i;
        }
        return -1;
    }
};
