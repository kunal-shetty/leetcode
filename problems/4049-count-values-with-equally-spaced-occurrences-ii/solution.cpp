// 4049. Count Values With Equally Spaced Occurrences II
// Difficulty: Medium
// https://leetcode.com/problems/count-values-with-equally-spaced-occurrences-ii/
// Runtime: 314 ms (beats —)
// Memory: 318.9 MB (beats —)
// Submitted: 2026-09-12

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        unordered_map<int, vector<int>> pos;
        for(int i = 0;i <nums.size(); i++){
            pos[nums[i]].push_back(i);
        }
        int res = 0;
        for(auto entry : pos){
            if(entry.second.size() < 3) continue;
            int d = entry.second[1] - entry.second[0];
            bool k = true;
            for(int i = 2; i < entry.second.size(); i++){
                if(entry.second[i] - entry.second[i - 1] != d){
                    k = false;
                    break;
                }
            }
            if(k) res++;
        }
        return res;
    }
};
