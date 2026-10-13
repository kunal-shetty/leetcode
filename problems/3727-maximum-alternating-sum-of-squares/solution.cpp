// 3727. Maximum Alternating Sum of Squares
// Difficulty: Medium
// https://leetcode.com/problems/maximum-alternating-sum-of-squares/
// Runtime: 72 ms (beats —)
// Memory: 212.2 MB (beats —)
// Submitted: 2026-10-13

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
       
        long long n = nums.size(), sum = 0, i = 0, j = n - 1;
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] * nums[i];
        }
        sort(nums.begin(), nums.end());
        vector<long long> res;
        
        while (i < j) {
            if (i == j) {
                res.push_back(nums[i]);
                break;
            }
            res.push_back(nums[j]);
            res.push_back(nums[i]);
            j--, i++;
        }
        if (n & 1) res.push_back(nums[n/2]);
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) sum += res[i];
            else sum -= res[i];
        }
        return sum;
   
    }
};
