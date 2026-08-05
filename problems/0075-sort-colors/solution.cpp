// 75. Sort Colors
// Difficulty: Medium
// https://leetcode.com/problems/sort-colors/
// Runtime: 0 ms (beats —)
// Memory: 11.6 MB (beats —)
// Submitted: 2026-08-05

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero = 0, one = 0, two = 0;
        for(auto num : nums){
            if(num == 0) zero++;
            if(num == 1) one++;
            if(num == 2) two++;
        }
        int i = 0;
        while( i < nums.size()){
            while(zero){
                nums[i] = 0;
                zero--;
                i++;
            }
            while(one){
                nums[i] = 1;
                one--;
                i++;
            }
            while(two){
                nums[i] = 2;
                two--;
                i++;
            }
        }
    }
};
