// 1464. Maximum Product of Two Elements in an Array
// Difficulty: Easy
// https://leetcode.com/problems/maximum-product-of-two-elements-in-an-array/
// Runtime: 0 ms (beats —)
// Memory: 13.6 MB (beats —)
// Submitted: 2026-07-27

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int firstMax = 0, secondMax = 0;
        for(auto num : nums){
            if(num > firstMax){
                secondMax = firstMax;
                firstMax = num;
            }
            else if(num > secondMax){
                secondMax = num;
            }
        }
        return (firstMax - 1) * (secondMax - 1);
    }
};
