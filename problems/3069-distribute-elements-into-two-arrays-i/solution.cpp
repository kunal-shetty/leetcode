// 3069. Distribute Elements Into Two Arrays I
// Difficulty: Easy
// https://leetcode.com/problems/distribute-elements-into-two-arrays-i/
// Runtime: 0 ms (beats —)
// Memory: 24 MB (beats —)
// Submitted: 2026-08-20

class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> arr1, arr2;
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            if (arr1.back() > arr2.back())
                arr1.push_back(nums[i]);
            else
                arr2.push_back(nums[i]);
        }
        vector<int> res(arr1.begin(), arr1.end());
        res.insert(res.end(), arr2.begin(), arr2.end());

        return res;
    }
};
