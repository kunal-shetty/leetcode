// 3899. Angles of a Triangle
// Difficulty: Medium
// https://leetcode.com/problems/angles-of-a-triangle/
// Runtime: 4 ms (beats —)
// Memory: 29 MB (beats —)
// Submitted: 2026-04-12

class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        double a = sides[0], b = sides[1], c = sides[2];
        if (a + b <= c || b + c <= a || c + a <= b) {
            return {};
        }
        double A = acos((b * b + c * c - a * a) / (2 * b * c));
        double B = acos((a * a + c * c - b * b) / (2 * a * c));
        double C = acos((a * a + b * b - c * c) / (2 * a * b));

        double pi = acos(-1);
        A = A * 180.0 / pi;
        B = B * 180.0 / pi;
        C = C * 180.0 / pi;

        vector<double> ans = {A, B, C};
        sort(ans.begin(), ans.end());
        return ans;
    }
};
