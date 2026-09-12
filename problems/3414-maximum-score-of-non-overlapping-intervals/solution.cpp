// 3414. Maximum Score of Non-overlapping Intervals
// Difficulty: Hard
// https://leetcode.com/problems/maximum-score-of-non-overlapping-intervals/
// Runtime: 844 ms (beats —)
// Memory: 326.5 MB (beats —)
// Submitted: 2026-09-12

class Solution {
    using T = tuple<int, int, int, int>;

    static bool compareRight(const T& a, const T& b) {
        return get<1>(a) < get<1>(b);
    }

    static bool rightLessThan(const T& t, int val) { return get<1>(t) < val; }

    static vector<int> mergeSorted(vector<int> a, int x) {
        a.push_back(x);
        sort(a.begin(), a.end());
        return a;
    }

public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<T> arr;
        for (int i = 0; i < n; i++)
            arr.emplace_back(intervals[i][0], intervals[i][1], intervals[i][2],
                             i);

        sort(arr.begin(), arr.end(), compareRight);

        vector<vector<long long>> dp(n + 1, vector<long long>(5));
        vector<vector<vector<int>>> idxs(n + 1, vector<vector<int>>(5));

        for (int i = 0; i < n; i++) {
            auto [l, r, w, idx] = arr[i];
            int k =
                lower_bound(arr.begin(), arr.begin() + i, l, rightLessThan) -
                arr.begin();

            for (int j = 1; j < 5; j++) {
                long long s1 = dp[i][j], s2 = dp[k][j - 1] + w;
                auto ni = mergeSorted(idxs[k][j - 1], idx);

                if (s1 > s2 || (s1 == s2 && idxs[i][j] < ni)) {
                    dp[i + 1][j] = dp[i][j];
                    idxs[i + 1][j] = idxs[i][j];
                } else {
                    dp[i + 1][j] = s2;
                    idxs[i + 1][j] = ni;
                }
            }
        }
        return idxs[n][4];
    }
};
