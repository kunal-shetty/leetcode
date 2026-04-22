// 2452. Words Within Two Edits of Dictionary
// Difficulty: Medium
// https://leetcode.com/problems/words-within-two-edits-of-dictionary/
// Runtime: 8 ms (beats —)
// Memory: 18.8 MB (beats —)
// Submitted: 2026-04-22

class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries,
                                vector<string>& dictionary) {
        vector<string> ans;
        const int q = queries.size(), s = queries[0].size();
        for (int j = 0; j < q; j++) {
            const string query = queries[j];
            for (const string d : dictionary) {
                int diff = 0;
                for (int i = 0; i < s; i++) {
                    diff += query[i] != d[i];
                    if (diff > 2)
                        break;
                }
                if (diff <= 2) {
                    ans.push_back(query);
                    break;
                }
            }
        }
        return ans;
    }
};
