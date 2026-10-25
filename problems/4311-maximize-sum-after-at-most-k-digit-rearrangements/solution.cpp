// 4311. maximize sum after at most k digit rearrangements
// Difficulty: Unknown
// https://leetcode.com/problems/maximize-sum-after-at-most-k-digit-rearrangements/
// Runtime: 428 ms (beats 25.0%)
// Memory: 149 MB (beats 58.3%)
// Submitted: 2026-10-25

class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        vector<int> gain;
        for(auto num : nums){
            string s = to_string(num);
            sort(s.rbegin(), s.rend());
            gain.push_back(stoi(s) - num);
        sum += num;
        }
        sort(gain.rbegin(), gain.rend());
        for(int i = 0; i <k;i++){
            sum += gain[i];
        }
        return sum;
    }
    
};
