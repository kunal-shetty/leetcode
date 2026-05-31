// 2433. Find The Original Array of Prefix Xor
// Difficulty: Medium
// https://leetcode.com/problems/find-the-original-array-of-prefix-xor/
// Runtime: 6 ms (beats —)
// Memory: 83.6 MB (beats —)
// Submitted: 2026-05-31

class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        vector<int> res;
        int temp = pref[0];
        for(int i = 1; i < pref.size(); i++){
            
            res.push_back(temp);
            temp  =pref[i] ^ pref[i - 1];
        }
        res.push_back(temp);
        return res;
    }
};
