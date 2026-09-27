// 4066. Maximum Equal Adjacent Pairs After at Most One Replacement
// Difficulty: Medium
// https://leetcode.com/problems/maximum-equal-adjacent-pairs-after-at-most-one-replacement/
// Runtime: 919 ms (beats —)
// Memory: 494 MB (beats —)
// Submitted: 2026-09-27

class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        unordered_map<int, int> id;
        int idx = 0;
        for(auto num : nums){
            if(!id.count(num)) id[num] = idx++;
            
        }
        int base = 0;
        unordered_map<long long, int> gain;
            for(int i = 0; i + 1 < nums.size(); i++){
                if(nums[i] ==nums[i + 1]){
                    base++;
                }
                else {
                       int a = id[nums[i]], b = id[nums[i + 1]];
                        gain[1LL *a*idx + b]++;
                        gain[1LL *b*idx + a]++;
                }
            }
        int res = base;
            for(auto g : gain){
                res = max(res, g.second + base);
            }
    return res;
    }
    
};
