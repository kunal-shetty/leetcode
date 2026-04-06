// 874. Walking Robot Simulation
// Difficulty: Medium
// https://leetcode.com/problems/walking-robot-simulation/
// Runtime: 70 ms (beats —)
// Memory: 39.9 MB (beats —)
// Submitted: 2026-04-06

class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        vector<pair<int, int>> directions;
        directions.push_back({0, 1});
        directions.push_back({1, 0});
        directions.push_back({0, -1});
        directions.push_back({-1, 0});

        int dir = 0;
        int x = 0, y = 0;
        int maxDist = 0;

        unordered_set<string> obs;
        for (int i = 0; i < obstacles.size(); i++) {
            string key =
                to_string(obstacles[i][0]) + "," + to_string(obstacles[i][1]);
            obs.insert(key);
        }

        for (int i = 0; i < commands.size(); i++) {
            int cmd = commands[i];

            if (cmd == -1) {
                dir = (dir + 1) % 4;
            } else if (cmd == -2) {
                dir = (dir + 3) % 4;
            } else {
                for (int step = 0; step < cmd; step++) {
                    int nx = x + directions[dir].first;
                    int ny = y + directions[dir].second;

                    string key = to_string(nx) + "," + to_string(ny);

                    if (obs.count(key)) {
                        break;
                    }

                    x = nx;
                    y = ny;

                    int dist = x * x + y * y;
                    if (dist > maxDist) {
                        maxDist = dist;
                    }
                }
            }
        }

        return maxDist;
    }
};
