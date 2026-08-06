// 3838. Weighted Word Mapping
// Difficulty: Easy
// https://leetcode.com/problems/weighted-word-mapping/
// Runtime: 0 ms (beats —)
// Memory: 43.9 MB (beats —)
// Submitted: 2026-08-06

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string alphabets = "zyxwvutsrqponmlkjihgfedcba";
        string res = "";

        for (auto word : words) {
            int weight = 0;

            for (auto letter : word) {
                weight += weights[letter - 'a'];
            }

            res += alphabets[weight % 26];
        }

        return res;
    }
};
