// 1504. Count Submatrices With All Ones
// Difficulty: Medium
// https://leetcode.com/problems/count-submatrices-with-all-ones/
// Runtime: 8 ms (beats —)
// Memory: 21.4 MB (beats —)
// Submitted: 2026-06-13

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();

        vector<int> height(n, 0);
        int ans = 0;

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1)
                    height[j]++;
                else
                    height[j] = 0;
            }

            stack<int> st;
            vector<int> dp(n, 0);

            for (int j = 0; j < n; j++) {

                while (!st.empty() && height[st.top()] >= height[j])
                    st.pop();

                if (st.empty()) {
                    dp[j] = height[j] * (j + 1);
                } else {
                    int prev = st.top();
                    dp[j] = dp[prev] + height[j] * (j - prev);
                }

                st.push(j);
                ans += dp[j];
            }
        }

        return ans;
    }
};
