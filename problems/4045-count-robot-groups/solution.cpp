// 4045. Count Robot Groups
// Difficulty: Medium
// https://leetcode.com/problems/count-robot-groups/
// Runtime: 15 ms (beats —)
// Memory: 215.2 MB (beats —)
// Submitted: 2026-09-06

class Solution {
public:
    int countGroups(vector<int>& position, vector<int>& speed, int distance) {
        int n = position.size(), res = 0;
        vector<double> time(n, -1);
        stack<int> st;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty()) {
                int j = st.top();

                if (position[j] - position[i] <= distance) {
                    time[i] = 0;
                    break;
                }
                if (speed[i] <= speed[j])
                    st.pop();
                else {
                    double t = max(0.0, (position[j] - position[i] - distance) *
                                            1.0 / (speed[i] - speed[j]));

                    if (time[j] < 0 || t <= time[j]) {
                        time[i] = t;
                        break;
                    }
                    st.pop();
                }
            }
            st.push(i);
        }
        for (auto t : time) {
            res += t < 0;
        }
        return res;
    }
};
