// 3668. Restore Finishing Order
// Difficulty: Easy
// https://leetcode.com/problems/restore-finishing-order/
// Runtime: 12 ms (beats —)
// Memory: 52.6 MB (beats —)
// Submitted: 2026-05-19

class Solution {
public:
    vector<int> recoverOrder(vector<int>& order, vector<int>& friends) {
        unordered_map<int, int> map;
        for(int f : friends) map[f]++;
        vector<int> res;
        for(auto it : order){
            if(map[it]) res.push_back(it);
        }
        return res;
    }
};
