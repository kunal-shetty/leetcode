// 739. Daily Temperatures
// Difficulty: Medium
// https://leetcode.com/problems/daily-temperatures/
// Runtime: 19 ms (beats —)
// Memory: 107.5 MB (beats —)
// Submitted: 2026-09-05

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size());
        stack<int> st;
        for(int i = 0; i < temperatures.size(); i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                res[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }
        return res;
    }
};
