// 4038. Count Integers Appearing in a Single Block
// Difficulty: Easy
// https://leetcode.com/problems/count-integers-appearing-in-a-single-block/
// Runtime: 0 ms (beats —)
// Memory: 20.9 MB (beats —)
// Submitted: 2026-08-30

class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        vector<int> b(101, 0);
        for(int i=0; i < nums.size();i++){
            if(i ==0 ||nums[i] != nums[i-1]) b[nums[i]]++;
        }
        int res =0;
        for(int i =1;i <=100;i++){
            if(b[i] == 1) res++;
        }
        return res;
    }
};
