// 3661. Maximum Walls Destroyed by Robots
// Difficulty: Hard
// https://leetcode.com/problems/maximum-walls-destroyed-by-robots/
// Runtime: 159 ms (beats —)
// Memory: 190.1 MB (beats —)
// Submitted: 2026-04-03

class Solution {
public:
    int maxWalls(vector<int>& robots, vector<int>& distance,
                 vector<int>& walls) {

        int n = robots.size();

        vector<pair<int, int>> r(n);
        for (int i = 0; i < n; i++) {
            r[i] = {robots[i], distance[i]};
        }

        sort(r.begin(), r.end());
        sort(walls.begin(), walls.end());

        vector<int> left(n), right(n), num(n);

        for (int i = 0; i < n; i++) {
            int robot = r[i].first;
            int dist = r[i].second;

            int pos1 =
                upper_bound(walls.begin(), walls.end(), robot) - walls.begin();

            int leftLimit = robot - dist;
            if (i > 0)
                leftLimit = max(leftLimit, r[i - 1].first + 1);

            int leftPos = lower_bound(walls.begin(), walls.end(), leftLimit) -
                          walls.begin();
            left[i] = pos1 - leftPos;

            int rightLimit = robot + dist;
            if (i < n - 1)
                rightLimit = min(rightLimit, r[i + 1].first - 1);

            int pos2 =
                lower_bound(walls.begin(), walls.end(), robot) - walls.begin();
            int rightPos = upper_bound(walls.begin(), walls.end(), rightLimit) -
                           walls.begin();
            right[i] = rightPos - pos2;

            if (i > 0) {
                int prevRobot = r[i - 1].first;
                int pos3 = lower_bound(walls.begin(), walls.end(), prevRobot) -
                           walls.begin();
                num[i] = pos1 - pos3;
            }
        }

        int subLeft = left[0];
        int subRight = right[0];

        for (int i = 1; i < n; i++) {
            int currentLeft =
                max(subLeft + left[i], subRight - right[i - 1] +
                                           min(left[i] + right[i - 1], num[i]));

            int currentRight = max(subLeft + right[i], subRight + right[i]);

            subLeft = currentLeft;
            subRight = currentRight;
        }

        return max(subLeft, subRight);
    }
};
