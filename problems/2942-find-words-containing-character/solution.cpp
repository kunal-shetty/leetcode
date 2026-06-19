// 2942. Find Words Containing Character
// Difficulty: Easy
// https://leetcode.com/problems/find-words-containing-character/
// Runtime: 0 ms (beats —)
// Memory: 32.9 MB (beats —)
// Submitted: 2026-06-19

class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        for(int i = 0; i < words.size(); i++){
            if(words[i].contains(x)) res.push_back(i);
        }
        return res;
    }
};
