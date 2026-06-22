// 1282. Group the People Given the Group Size They Belong To
// Difficulty: Medium
// https://leetcode.com/problems/group-the-people-given-the-group-size-they-belong-to/
// Runtime: 9 ms (beats —)
// Memory: 18.1 MB (beats —)
// Submitted: 2026-06-22

class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        unordered_map<int, vector<int>> freq;

        for (int i = 0; i < groupSizes.size(); i++) {
            freq[groupSizes[i]].push_back(i);
        }

        vector<vector<int>> res;

        for (auto entry : freq) {
            int s = entry.first;

            for (int i = 0; i < entry.second.size(); i += s) {
                vector<int> group;

                for (int j = i; j < i + s; j++) {
                    group.push_back(entry.second[j]);
                }

                res.push_back(group);
            }
        }

        return res;
    }
};
