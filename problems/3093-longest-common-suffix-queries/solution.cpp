// 3093. Longest Common Suffix Queries
// Difficulty: Hard
// https://leetcode.com/problems/longest-common-suffix-queries/
// Runtime: 1012 ms (beats —)
// Memory: 317.4 MB (beats —)
// Submitted: 2026-05-28

class Solution {
public:
    vector<int> stringIndices(vector<string>& wordsContainer,
                              vector<string>& wordsQuery) {
        unordered_map<unsigned long long, int> mp;
        int best = 0;
        for (int i = 1; i < wordsContainer.size(); i++) {
            if (wordsContainer[i].size() < wordsContainer[best].size())
                best = i;
        }
        const unsigned long long base = 131;
        for (int i = 0; i < wordsContainer.size(); i++) {
            unsigned long long h = 0;
            for (int j = wordsContainer[i].size() - 1; j >= 0; j--) {
                h = h * base + wordsContainer[i][j];
                if (!mp.count(h) ||
                    wordsContainer[i].size() < wordsContainer[mp[h]].size()) {
                    mp[h] = i;
                }
            }
        }
        vector<int> ans;
        for (string& q : wordsQuery) {
            unsigned long long h = 0;
            int res = best;
            for (int i = q.size() - 1; i >= 0; i--) {
                h = h * base + q[i];
                if (mp.count(h))
                    res = mp[h];
            }
            ans.push_back(res);
        }
        return ans;
    }
};
