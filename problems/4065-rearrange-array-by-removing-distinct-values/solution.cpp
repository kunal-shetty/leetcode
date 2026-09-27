// 4065. Rearrange Array by Removing Distinct Values
// Difficulty: Easy
// https://leetcode.com/problems/rearrange-array-by-removing-distinct-values/
// Runtime: 4 ms (beats —)
// Memory: 33.8 MB (beats —)
// Submitted: 2026-09-27

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> freq(101, 0), res;
        for(auto num : nums){
            freq[num]++;
        }
        int left = nums.size();
        while(left){
            for(int i = 1; i <= 100;i++){
                if(freq[i]){
                    res.push_back(i);
                    freq[i]--;
                    left--;
                    
                }
            }
        }
        return res;
    }
};
