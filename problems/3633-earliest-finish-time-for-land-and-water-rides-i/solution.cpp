// 3633. Earliest Finish Time for Land and Water Rides I
// Difficulty: Easy
// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-i/
// Runtime: 3 ms (beats —)
// Memory: 91.9 MB (beats —)
// Submitted: 2026-06-02

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int res = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int land = landStartTime[i] + landDuration[i];
                int landWater =
                    max(land, waterStartTime[j]) + waterDuration[j];
                res = min(res, landWater);

                int water = waterStartTime[j] + waterDuration[j];
                int waterLand = max(water, landStartTime[i]) + landDuration[i];
                res = min(res, waterLand);
            }
        }
        return res;
    }
};
