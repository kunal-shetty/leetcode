// 3917. Count Indices With Opposite Parity
// Difficulty: Easy
// https://leetcode.com/problems/count-indices-with-opposite-parity/
// Runtime: 0 ms (beats —)
// Memory: 32.8 MB (beats —)
// Submitted: 2026-05-03

class Solution {
public:
    bool parityCheck(int num){
        return num % 2;
    } 
    vector<int> countOppositeParity(vector<int>& nums) {
        int size = nums.size();
        vector<int> scores(size, 0);

        int evenCount = 0, oddCount = 0;

        for(int i = 0; i < size; i++){
            if(parityCheck(nums[i])) oddCount++;
            else evenCount++;
        }

        for(int i = 0; i < size; i++){
            if(parityCheck(nums[i])){
                oddCount--;
                scores[i] = evenCount;
            } else {
                evenCount--;
                scores[i] = oddCount;
            }
        }

        return scores;
    }
};
