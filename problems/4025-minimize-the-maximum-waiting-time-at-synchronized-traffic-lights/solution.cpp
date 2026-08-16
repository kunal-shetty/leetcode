// 4025. Minimize the Maximum Waiting Time at Synchronized Traffic Lights
// Difficulty: Medium
// https://leetcode.com/problems/minimize-the-maximum-waiting-time-at-synchronized-traffic-lights/
// Runtime: 4 ms (beats —)
// Memory: 178.7 MB (beats —)
// Submitted: 2026-08-16

class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {
        int maxlight = *max_element(lights.begin(), lights.end());
        int ans = 0;
        for (int t : arrivalTime) {
            int r = t % period;
            int w = 0;
            if (r >= maxlight) {
                w = period - r;
            }
            ans = max(ans, w);
        }
        return ans;
    }
};
