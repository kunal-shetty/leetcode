// 2391. Minimum Amount of Time to Collect Garbage
// Difficulty: Medium
// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/
// Runtime: 37 ms (beats —)
// Memory: 108.9 MB (beats —)
// Submitted: 2026-06-01

class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n = garbage.size();

        vector<int> prefix(n, 0);
        for (int i = 1; i < n; i++) {
            prefix[i] = prefix[i - 1] + travel[i - 1];
        }

        int glass = 0, paper = 0, metal = 0;
        int lastGlass = 0, lastPaper = 0, lastMetal = 0;

        for (int i = 0; i < n; i++) {
            glass += count(garbage[i].begin(), garbage[i].end(), 'G');
            paper += count(garbage[i].begin(), garbage[i].end(), 'P');
            metal += count(garbage[i].begin(), garbage[i].end(), 'M');

            if (garbage[i].find('G') != string::npos) lastGlass = i;
            if (garbage[i].find('P') != string::npos) lastPaper = i;
            if (garbage[i].find('M') != string::npos) lastMetal = i;
        }

        glass += prefix[lastGlass];
        paper += prefix[lastPaper];
        metal += prefix[lastMetal];

        return glass + paper + metal;
    }
};
