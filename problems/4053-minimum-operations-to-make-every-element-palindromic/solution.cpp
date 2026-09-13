// 4053. Minimum Operations to Make Every Element Palindromic
// Difficulty: Medium
// https://leetcode.com/problems/minimum-operations-to-make-every-element-palindromic/
// Runtime: 85 ms (beats —)
// Memory: 137.9 MB (beats —)
// Submitted: 2026-09-13

class Solution {
public:
    static vector<int> even, odd;
    static bool done;
    void run(){
        if(done) return;
        done = true;
        if(!even.empty()) return;
        for(int i =1; i<=9;i++){
            int k = (i + 1) / 2;
            int s = (i == 1 ? 1 : pow(10, k - 1));
            int e = pow(10, k );
            for(int j = s; j < e; j++){
                string a = to_string(j);
                string b = a;
                int k = (i & 1 ? a.size() - 2 : a.size() - 1);
                while(k >= 0){
                    b += a[k];
                    k--;
                }
                long long x = stoll(b);
                if(x > 1000000000) continue;
                if(x &1 ) odd.push_back(x);
                else even.push_back(x);
            }
        }
    }
    long long minOperations(vector<int>& nums) {
        run();
        long long res = 0;
        for(auto num : nums){
            vector<int> &v = (num % 2 ? odd : even);
            auto it = lower_bound(v.begin(), v.end(), num);
            long long b = 1e18;
            if(it != v.end()) b = min(b, abs((long long)num - *it));
            if(it != v.begin()){
                it--;
                b = min(b, abs((long long)num - *it));
            }
            res += b /2;
        }
        return res;
    }
};
vector<int> Solution::even;
vector<int> Solution::odd;
bool Solution::done = false;
