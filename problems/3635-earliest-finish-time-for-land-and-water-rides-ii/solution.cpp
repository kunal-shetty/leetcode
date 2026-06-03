// 3635. Earliest Finish Time for Land and Water Rides II
// Difficulty: Medium
// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/
// Runtime: 0 ms (beats —)
// Memory: 238.1 MB (beats —)
// Submitted: 2026-06-03

class Solution {
public:
    int calFinishTime(vector<int>& landStart, vector<int>& landDuration,
                      vector<int>& waterStart, vector<int>& waterDuration) {

        int minimum = INT_MAX, ans = INT_MAX;

        for (int i = 0; i < landStart.size(); i++) {
            minimum = min(minimum, landStart[i] + landDuration[i]);
        }

        for (int i = 0; i < waterStart.size(); i++) {
            int finish = max(minimum, waterStart[i]) + waterDuration[i];
            ans = min(ans, finish);
        }

        return ans;
    }

    int earliestFinishTime(vector<int>& landStartTime,
                           vector<int>& landDuration,
                           vector<int>& waterStartTime,
                           vector<int>& waterDuration) {

        int landFirst = calFinishTime(
            landStartTime, landDuration,
            waterStartTime, waterDuration
        );

        int waterFirst = calFinishTime(
            waterStartTime, waterDuration,
            landStartTime, landDuration
        );

        return min(landFirst, waterFirst);
    }
};
