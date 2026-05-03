// 451. Sort Characters By Frequency
// Difficulty: Medium
// https://leetcode.com/problems/sort-characters-by-frequency/
// Runtime: 4 ms (beats —)
// Memory: 11.7 MB (beats —)
// Submitted: 2026-05-03

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> frequency;
        for(char c : s) frequency[c]++;

        vector<pair<int,char>> entries;
        for(auto p : frequency) entries.push_back({p.second, p.first});

        sort(entries.rbegin(), entries.rend());

        string result = "";
        for(auto p : entries)
            result += string(p.first, p.second);

        return result;
    }
};
