// 2751. Robot Collisions
// Difficulty: Hard
// https://leetcode.com/problems/robot-collisions/
// Runtime: 65 ms (beats —)
// Memory: 205 MB (beats —)
// Submitted: 2026-04-01

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& p, vector<int>& h,
                                      string d) {
        int n = p.size();
        vector<array<int, 4>> a(n);

        for (int i = 0; i < n; i++)
            a[i] = {p[i], h[i], d[i], i};

        sort(a.begin(), a.end());

        stack<int> st;

        for (int i = 0; i < n; i++) {
            if (a[i][2] == 'R')
                st.push(i);
            else {
                while (!st.empty() && a[i][1]) {
                    int j = st.top();
                    if (a[j][1] < a[i][1]) {
                        a[i][1]--;
                        a[j][1] = 0;
                        st.pop();
                    } else if (a[j][1] > a[i][1]) {
                        a[j][1]--;
                        a[i][1] = 0;
                    } else {
                        a[j][1] = a[i][1] = 0;
                        st.pop();
                    }
                }
            }
        }

        vector<int> res(n, 0);
        for (int i = 0; i < n; i++)
            if (a[i][1])
                res[a[i][3]] = a[i][1];

        vector<int> ans;
        for (int i = 0; i < n; i++)
            if (res[i])
                ans.push_back(res[i]);

        return ans;
    }
};
