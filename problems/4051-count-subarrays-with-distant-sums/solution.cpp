// 4051. Count Subarrays with Distant Sums
// Difficulty: Hard
// https://leetcode.com/problems/count-subarrays-with-distant-sums/
// Runtime: 143 ms (beats —)
// Memory: 124.8 MB (beats —)
// Submitted: 2026-09-12

class Solution {
public:
    struct BIT {
        vector<int> bit;
        BIT(int n) : bit(n + 1) {}
        void add(int i) {
            i++;
            while (i < bit.size()) {
                bit[i]++;
                i += i & -i;
            }
        }
        int query(int i) {
            i++;
            int s = 0;
            while (i > 0) {
                s += bit[i];
                i -= i & -i;
            }
            return s;
        }
    };
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        int n = nums.size();
        vector<long long> pre(n + 1);
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + nums[i];

        vector<long long> vals = pre;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        BIT bit(vals.size());
        bit.add(lower_bound(vals.begin(), vals.end(), pre[0]) - vals.begin());

        long long res = 0;
        for (int i = 1; i <= n; i++) {
            long long p = pre[i];
            int l = upper_bound(vals.begin(), vals.end(), p - goal - k) -
                    vals.begin() - 1;
            if (l >= 0)
                res += bit.query(l);
            int r = lower_bound(vals.begin(), vals.end(), p - goal + k) -
                    vals.begin();
            res += i - (r ? bit.query(r - 1) : 0);

            if (k == 0) {
                long long target = p - goal;
                int low = lower_bound(vals.begin(), vals.end(), target) -
                          vals.begin();
                int high = upper_bound(vals.begin(), vals.end(), target) -
                           vals.begin() - 1;
                if (low <= high)
                    res -= bit.query(high) - (low ? bit.query(low - 1) : 0);
            }
            bit.add(lower_bound(vals.begin(), vals.end(), p) - vals.begin());
        }
        return res;
    }
};
