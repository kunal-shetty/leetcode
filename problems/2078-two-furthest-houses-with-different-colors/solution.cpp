// 2078. Two Furthest Houses With Different Colors
// Difficulty: Easy
// https://leetcode.com/problems/two-furthest-houses-with-different-colors/
// Runtime: 0 ms (beats —)
// Memory: 12 MB (beats —)
// Submitted: 2026-04-20

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int maxDist = INT_MIN;
        for(int i = 0; i < colors.size(); i++){
            for(int j = 0; j < colors.size(); j++){
                if(colors[i] != colors[j]) 
                maxDist = max(maxDist, abs(i - j));
            }
        }
        return maxDist;
    }
};
