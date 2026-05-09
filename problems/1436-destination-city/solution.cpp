// 1436. Destination City
// Difficulty: Easy
// https://leetcode.com/problems/destination-city/
// Runtime: 4 ms (beats —)
// Memory: 16.6 MB (beats —)
// Submitted: 2026-05-09

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, string> trips;

        for (auto path : paths) {
            trips[path[0]] = path[1];
        }

        string destination = "";

        for (auto path : paths) {
            if (!trips.count(path[1])) {
                destination = path[1];
            }
        }

        return destination;
    }
};
