// 3992. Rearrange String to Avoid Character Pair
// Difficulty: Easy
// https://leetcode.com/problems/rearrange-string-to-avoid-character-pair/
// Runtime: 0 ms (beats —)
// Memory: 10.5 MB (beats —)
// Submitted: 2026-07-18

class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        unordered_map<char, int> map;
        for(auto ch : s){
            map[ch]++;
        }
        string res = "";
        int count = map[y];
        while(count){
            res += y;
            count--;
        }
        for(auto entry : map){
            if(entry.first == y) continue;
            while(entry.second){
            res += entry.first;
                entry.second--;
            }
        }
        return res;
    }
};
