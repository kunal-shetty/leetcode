// 4059. Lexicographically Largest Power Array
// Difficulty: Hard
// https://leetcode.com/problems/lexicographically-largest-power-array/
// Runtime: 127 ms (beats —)
// Memory: 358.2 MB (beats —)
// Submitted: 2026-09-20

class Solution {
public:
    vector<int> largestPower(vector<int>& nums) {
        vector<vector<int>> groups = {nums};
        vector<int> power;
        for (int b = 14; b >= 0; b--) {
            vector<vector<int>> n;
            vector<int> rem;
            int curr = 0;
            bool s = false;

for (auto group : groups) {
    if (s) {
        n.push_back(group);
        continue;
    }

    vector<int> one, zero;
    for (auto g : group) {
        if ((g >> b) & 1) one.push_back(g);
        else zero.push_back(g);
    }

    if (zero.empty()) {
        curr += one.size();
        n.push_back(one);
    }
    else if (one.empty()) {
        s = true;
        n.push_back(group);
    }
    else {
        curr += one.size();
        s = true;
        n.push_back(one);
        n.push_back(zero);
    }
}
            power.push_back(curr);
            groups = n;
        }
        return power;
    }
};
