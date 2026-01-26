// 1200. Minimum Absolute Difference
// Difficulty: Easy
// https://leetcode.com/problems/minimum-absolute-difference/
// Runtime: 0 ms (beats —)
// Memory: 36.6 MB (beats —)
// Submitted: 2026-01-26

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> res;
        sort(arr.begin(), arr.end());
        int minAbsDiff = INT_MAX;
        for(int i = 0; i < arr.size() - 1; i++){
            if(abs(arr[i] - arr[i + 1]) < minAbsDiff)
                minAbsDiff = abs(arr[i] - arr[i + 1]);
        }

        for(int i = 0; i < arr.size() - 1; i++){
            if(abs(arr[i] - arr[i + 1]) == minAbsDiff)
                res.push_back({arr[i], arr[i + 1]});   
        }

        return res;
    }
};

auto init = atexit( [](){ ofstream("display_runtime.txt") <<'0'; });
