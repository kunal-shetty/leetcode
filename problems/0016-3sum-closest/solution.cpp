// 16. 3Sum Closest
// Difficulty: Medium
// https://leetcode.com/problems/3sum-closest/
// Runtime: 12 ms (beats —)
// Memory: 14 MB (beats —)
// Submitted: 2026-01-28

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int closestSum = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < n - 2; i++) {
            int j = i + 1, k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];

                // update closest sum
                if (abs(sum - target) < abs(closestSum - target)) {
                    closestSum = sum;
                }

                if (sum < target) {
                    j++;
                } else if (sum > target) {
                    k--;
                } else {
                    // exact match
                    return sum;
                }
            }
        }
        return closestSum;
    }
};
