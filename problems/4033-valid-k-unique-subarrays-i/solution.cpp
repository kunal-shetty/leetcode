// 4033. Valid K-Unique Subarrays I
// Difficulty: Hard
// https://leetcode.com/problems/valid-k-unique-subarrays-i/
// Runtime: 397 ms (beats —)
// Memory: 340.3 MB (beats —)
// Submitted: 2026-08-23

    class Solution {
    public:

        static int B;
        vector<int> freq;
        int unique = 0,  odd = 0;

        static bool compare ( const vector<int> &a, const vector<int>& b ){
                int x= a[0] /B, y = b[0] / B;;
                if(x != y) return x < y;
                    return (x &1) ? a[1] > b[1] : a[1] < b[1];
            }


        void add(int x){
            if(freq[x] == 0) unique++;
            if(freq[x] % 2) odd--;
            else odd++;
            freq[x]++;
        }

        void remove (int x){
            if(freq[x] % 2) odd--;
            else odd++;
            freq[x]--;
            if(freq[x] == 0) unique--;
        }
        
        vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
            
            int n = nums.size(), q = queries.size();
            B = max(1, (int)sqrt(n));

            freq.assign(100001, 0);
        unique = 0,  odd = 0;
            

            vector<vector<int>> qs;
            for(int i = 0; i < q; i++){
                qs.push_back({queries[i][0], queries[i][1], i});
                
            }
            sort(qs.begin(), qs.end(), compare);
            vector<bool> ans(q);
            int L = 0, R = -1;
            for(auto  &query : qs){
                int l = query[0], r = query[1], idx = query[2];
                while(L > l) add(nums[--L]);
                while(R < r) add(nums[++R]);
                while(L < l) remove(nums[L++]);
                    while(R > r) remove (nums[R--]);

                ans[idx]  = (unique == k && odd == 0);
            }
            return ans;
        }
    };

    int Solution::B = 0;
