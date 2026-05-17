// 1306. Jump Game III
// Difficulty: Medium
// https://leetcode.com/problems/jump-game-iii/
// Runtime: 4 ms (beats —)
// Memory: 40.9 MB (beats —)
// Submitted: 2026-05-17

class Solution {
public:
bool check(int i, vector<int>& arr, vector<int>& visited){
    if(i < 0 || i >= arr.size() || visited[i] == 1) return false;
    if(arr[i] == 0) return true;
    visited[i] = 1;
    return check(i + arr[i], arr, visited) || check(i - arr[i], arr, visited);
    
}
    bool canReach(vector<int>& arr, int start) {
        vector<int> visited(arr.size(), 0);
        return check(start, arr, visited);
    }
};
