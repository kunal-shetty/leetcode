// 3948. Lexicographically Maximum MEX Array
// Difficulty: Hard
// https://leetcode.com/problems/lexicographically-maximum-mex-array/
// Runtime: 139 ms (beats —)
// Memory: 125.9 MB (beats —)
// Submitted: 2026-05-31

class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int n = nums.size();
        vector<int> freq(n + 2, 0);
        for(int num : nums) if(num <= n) freq[num]++;

        set<int> missing;
        for(int i = 0; i <= n; i++){
            if(freq[i] == 0) missing.insert(i);
        }

        vector<int> ans;
        vector<int> seen(n + 2, 0);
        int i = 0;
        int time = 1;
        while(i < n){
            int MEX = *missing.begin() ;
            if(MEX == 0){
                ans.push_back(0);
                int x = nums[i++];
                if(x <= n && --freq[x] == 0) missing.insert(x); 
            }
            else {
                ans.push_back(MEX);
                int gain = 0;
                while(gain < MEX){
                    int x = nums[i++];
                    if(x <= n && --freq[x] == 0) missing.insert(x);
                    if(x < MEX && seen[x] != time){
                        seen[x] = time;
                        gain++;
                    }
                }
                time++;
            }
        }
        return ans;
    }
};
