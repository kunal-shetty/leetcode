// 3919. Minimum Cost to Move Between Indices
// Difficulty: Medium
// https://leetcode.com/problems/minimum-cost-to-move-between-indices/
// Runtime: 75 ms (beats —)
// Memory: 249.1 MB (beats —)
// Submitted: 2026-05-03

class Solution {
public:
    vector<int> minCost(vector<int>& nums, vector<vector<int>>& queries) {
        int size = nums.size();

        vector<int> closest(size);
        for(int i = 0; i < size; i++){
            if(i == 0) closest[i] = 1;
            else if(i == size - 1) closest[i] = size - 2;
            else{
                int leftDiff = abs(nums[i] - nums[i - 1]);
                int rightDiff = abs(nums[i] - nums[i + 1]);
                if(leftDiff <= rightDiff) closest[i] = i - 1;
                else closest[i] = i + 1;
            }
        }

        vector<long long> forwardCost(size, 0);
        for(int i = 1; i < size; i++){
            if(closest[i - 1] == i){
                forwardCost[i] = forwardCost[i - 1] + 1;
            } else {
                forwardCost[i] = forwardCost[i - 1] + (nums[i] - nums[i - 1]);
            }
        }

        vector<long long> backwardCost(size, 0);
        for(int i = size - 2; i >= 0; i--){
            if(closest[i + 1] == i){
                backwardCost[i] = backwardCost[i + 1] + 1;
            } else {
                backwardCost[i] = backwardCost[i + 1] + (nums[i + 1] - nums[i]);
            }
        }

        vector<int> result;

        for(auto query : queries){
            int left = query[0];
            int right = query[1];

            if(left < right){
                result.push_back(forwardCost[right] - forwardCost[left]);
            } else {
                result.push_back(backwardCost[right] - backwardCost[left]);
            }
        }

        return result;
    }
};
