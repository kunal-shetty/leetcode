// 3923. Minimum Generations to Target Point
// Difficulty: Medium
// https://leetcode.com/problems/minimum-generations-to-target-point/
// Runtime: 845 ms (beats —)
// Memory: 229 MB (beats —)
// Submitted: 2026-05-09

class Solution {
public:
    int encode(vector<int>& p) { return p[0] * 100 + p[1] * 10 + p[2]; }

    int minGenerations(vector<vector<int>>& points, vector<int>& target) {

        unordered_set<int> seen;

        for (auto p : points) {

            seen.insert(encode(p));

            if (p == target)
                return 0;
        }

        if (points.size() < 2)
            return -1;

        vector<vector<int>> all = points;

        for (int gen = 1; gen <= 20; gen++) {

            vector<vector<int>> newPoints;

            int n = all.size();

            for (int i = 0; i < n; i++) {

                for (int j = i + 1; j < n; j++) {

                    if (all[i] == all[j])
                        continue;

                    vector<int> c = {(all[i][0] + all[j][0]) / 2,
                                     (all[i][1] + all[j][1]) / 2,
                                     (all[i][2] + all[j][2]) / 2};

                    int key = encode(c);

                    if (!seen.count(key)) {

                        if (c == target)
                            return gen;

                        seen.insert(key);
                        newPoints.push_back(c);
                    }
                }
            }

            if (newPoints.empty())
                break;

            for (auto p : newPoints) {
                all.push_back(p);
            }
        }

        return -1;
    }
};
