// 1807. Evaluate the Bracket Pairs of a String
// Difficulty: Medium
// https://leetcode.com/problems/evaluate-the-bracket-pairs-of-a-string/
// Runtime: 130 ms (beats —)
// Memory: 144.7 MB (beats —)
// Submitted: 2026-09-26

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> map;

        for (auto word : knowledge)
            map[word[0]] = word[1];

        string res = "";

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                string inner = "";
                i++;
                while (s[i] != ')') {
                    inner += s[i];
                    i++;
                }
                if (map.count(inner))
                    res += map[inner];
                else
                    res += '?';
            } else {
                res += s[i];
            }
        }

        return res;
    }
};
