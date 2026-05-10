// 3927. Minimize Array Sum Using Divisible Replacements
// Difficulty: Medium
// https://leetcode.com/problems/minimize-array-sum-using-divisible-replacements/
// Runtime: 619 ms (beats —)
// Memory: 187.8 MB (beats —)
// Submitted: 2026-05-10

class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        unordered_set<int> seen;
        long long answer = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            int minValue = nums[i];

            for (int d = 1; (long long)d * d <= nums[i]; d++) {
                if (nums[i] % d == 0) {
                    if (seen.count(d)) {
                        minValue = d;
                        break;
                    }
                    if (seen.count(nums[i] / d)) {
                        minValue = min(minValue, nums[i] / d);
                    }
                }
            }

            answer += minValue;
            seen.insert(nums[i]);
        }

        return answer;
    }
};
