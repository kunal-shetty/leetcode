// 1394. Find Lucky Integer in an Array
// Difficulty: Easy
// https://leetcode.com/problems/find-lucky-integer-in-an-array/
// Runtime: 1 ms (beats —)
// Memory: 14 MB (beats —)
// Submitted: 2026-08-05

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        int lucky = -1;
        for(auto a : arr){
            freq[a]++;
        }

        for(auto entry : freq){
            if(entry.first == entry.second) lucky = max(lucky, entry.first);
        }
        return lucky;
    }
};
