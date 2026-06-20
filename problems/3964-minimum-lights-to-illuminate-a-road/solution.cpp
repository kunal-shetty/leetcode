// 3964. Minimum Lights to Illuminate a Road
// Difficulty: Medium
// https://leetcode.com/problems/minimum-lights-to-illuminate-a-road/
// Runtime: 19 ms (beats —)
// Memory: 288.8 MB (beats —)
// Submitted: 2026-06-20

class Solution {
public:
    int minLights(vector<int>& lights) {
        int n = lights.size();
        vector<int> diff(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (lights[i] > 0) {
                int l = max(0, i - lights[i]);
                int r = min(n - 1, i + lights[i]);

                diff[l]++;
                diff[r + 1]--;
            }
        }

        vector<int> visible(n);
        int cur = 0;

        for (int i = 0; i < n; i++) {
            cur += diff[i];
            visible[i] = cur > 0;
        }

        int ans = 0;
        for (int i = 0; i < n;) {
            if (visible[i]) {
                i++;
                continue;
            }
            int j = i;
            while (j < n && !visible[j])
                j++;

            int len = j - i;
            ans += (len + 2) / 3;

            i = j;
        }
        return ans;
    }
};
