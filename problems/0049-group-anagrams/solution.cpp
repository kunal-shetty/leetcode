// 49. Group Anagrams
// Difficulty: Medium
// https://leetcode.com/problems/group-anagrams/
// Runtime: 18 ms (beats —)
// Memory: 26.1 MB (beats —)
// Submitted: 2026-09-02

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> freq;
        for(auto str : strs){
            string t = str;
            sort(t.begin(), t.end());
            freq[t].push_back(str);
        }
        vector<vector<string>> res;
        for(auto entry : freq){
            res.push_back(entry.second);
        }
        return res;
    }
};
