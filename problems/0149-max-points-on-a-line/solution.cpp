// 149. Max Points on a Line
// Difficulty: Hard
// https://leetcode.com/problems/max-points-on-a-line/
// Runtime: 23 ms (beats —)
// Memory: 17.7 MB (beats —)
// Submitted: 2026-06-01

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2) {
            return n;
        }
        int maxFreq = 0;
        for (int i = 0; i < n; i++) {
            unordered_map<double, int> freqs;
            for (int j = i + 1; j < n; j++) {

                double d = (points[i][0] - points[j][0]);
                double n = (points[i][1] - points[j][1]);
                double slope;

                if (d == 0)
                    slope = INT_MAX;
                else
                    slope = n / d;

                freqs[slope]++;
                maxFreq = max(freqs[slope], maxFreq);
            }
        }
        return maxFreq + 1;
    }
};
