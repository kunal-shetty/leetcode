// 1665. Minimum Initial Energy to Finish Tasks
// Difficulty: Hard
// https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/
// Runtime: 78 ms (beats —)
// Memory: 110.6 MB (beats —)
// Submitted: 2026-05-12

class Solution {
public:
    int minimumEffort(vector<vector<int>>& tasks) {
        sort(tasks.begin(), tasks.end(), [](vector<int>& a, vector<int>& b) {
            return (a[1] - a[0]) > (b[1] - b[0]);
        });
        int initial = 0;
        int current = 0;
        for(auto task : tasks){
            int actual = task[0];
            int min = task[1];
            if(current < min){
                int required = min - current;;
                current += required;
                initial += required;
            }
            current -= actual;
        }
        return initial;
    }
};
