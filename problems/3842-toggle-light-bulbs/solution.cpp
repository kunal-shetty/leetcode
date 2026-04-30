// 3842. Toggle Light Bulbs
// Difficulty: Easy
// https://leetcode.com/problems/toggle-light-bulbs/
// Runtime: 3 ms (beats —)
// Memory: 34.5 MB (beats —)
// Submitted: 2026-04-30

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int, int> count;
        vector<int> res;
        for(int i = 0; i < bulbs.size(); i++){
            count[bulbs[i]]++; 
        }
        for(auto c : count){
            if(c.second % 2 == 0) continue;
            res.push_back(c.first);
        }
        sort(res.begin(), res.end());
        return res;
    }
};
