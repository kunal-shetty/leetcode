// 4026. Maximum Gap Between Stations
// Difficulty: Medium
// https://leetcode.com/problems/maximum-gap-between-stations/
// Runtime: 62 ms (beats —)
// Memory: 72.2 MB (beats —)
// Submitted: 2026-08-16

class Solution {
public:
    int maximumGap(string skill, string station) {
        int n = skill.length();
        int m = station.length();
        vector<int> left(n), right(n);
        int j = 0;
        for (int i = 0; i < n; i++) {
            while (station[j] != skill[i]) {
                j++;
            }
            left[i] = j;
            ;
            j++;
        }
        j = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            while (station[j] != skill[i]) {
                j--;
            }
            right[i] = j;
            j--;
        }
        int ans = 0;
        for (int i = 1; i < n; i++) {
            ans = max(ans, right[i] - left[i - 1]);
        }
        return ans;
    }
};
