// 4013. Count Subarrays With Even Odd Ratio II
// Difficulty: Hard
// https://leetcode.com/problems/count-subarrays-with-even-odd-ratio-ii/
// Runtime: 131 ms (beats —)
// Memory: 91.6 MB (beats —)
// Submitted: 2026-08-02

class Fenwick {
public:
    int n;
    vector<int> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, int val) {
        while (idx <= n) {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }

    int sum(int idx) {
        int res = 0;
        while (idx > 0) {
            res += bit[idx];
            idx -= idx & -idx;
        }
        return res;
    }
};

class Solution {
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();

        vector<long long> pref(n + 1);
        vector<int> odd(n + 1);

        for (int i = 0; i < n; i++) {
            odd[i + 1] = odd[i] + (nums[i] & 1);
            int even = (i + 1) - odd[i + 1];
            pref[i + 1] = 1LL * b * even - 1LL * a * odd[i + 1];
        }

        vector<long long> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        vector<vector<int>> groups(n + 1);
        for (int i = 0; i <= n; i++) {
            groups[odd[i]].push_back(i);
        }
        Fenwick fw(vals.size());
        long long ans = 0;

        for (int curOdd = 1; curOdd <= odd[n]; curOdd++) {
            for (int idx : groups[curOdd - 1]) {
                int id = lower_bound(vals.begin(), vals.end(), pref[idx]) -
                         vals.begin() + 1;
                fw.add(id, 1);
            }

            for (int idx : groups[curOdd]) {
                int id = lower_bound(vals.begin(), vals.end(), pref[idx]) -
                         vals.begin() + 1;
                ans += fw.sum(vals.size()) - fw.sum(id - 1);
            }
        }
        return ans;
    }
};
