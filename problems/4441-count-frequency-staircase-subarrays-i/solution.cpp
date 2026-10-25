// 4441. count frequency staircase subarrays i
// Difficulty: Unknown
// https://leetcode.com/problems/count-frequency-staircase-subarrays-i/
// Runtime: 1545 ms (beats 31.8%)
// Memory: 435.3 MB (beats 50.0%)
// Submitted: 2026-10-25

class Solution {
public:
    int countStaircase(vector<int>& nums) {
        int n =nums.size();
        int res =0;
        int l = (sqrt(1 +8* n) - 1) /2;
        for(int i = 0; i <n;i++){
            unordered_map<int, int> freq;
            vector<int> order;
            for(int j = i; j < n && j - i + 1 <= l*(l+1)/2;j++){
                if(!freq[nums[j]]) order.push_back(nums[j]);
                freq[nums[j]]++;
                int d = order.size();
                if(j - i + 1 != d*(d+1)/2) continue;
                bool ok = true;
                for(int k = 0; k <d;k++){
                    if(freq[order[k]] != k +1){
                        ok = false;
                        break;
                    }
                }
                res += ok;
            }
        }
        return res;
    }
};
