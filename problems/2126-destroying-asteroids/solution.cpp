// 2126. Destroying Asteroids
// Difficulty: Medium
// https://leetcode.com/problems/destroying-asteroids/
// Runtime: 23 ms (beats —)
// Memory: 106.8 MB (beats —)
// Submitted: 2026-05-31

class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        for(int asteroid : asteroids){
            if(asteroid > m) return false;
            m += asteroid;
        }
        return true;
    }
};
