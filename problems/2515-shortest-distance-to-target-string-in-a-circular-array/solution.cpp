// 2515. Shortest Distance to Target String in a Circular Array
// Difficulty: Easy
// https://leetcode.com/problems/shortest-distance-to-target-string-in-a-circular-array/
// Runtime: 0 ms (beats —)
// Memory: 18.4 MB (beats —)
// Submitted: 2026-04-15

class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        vector<int> arr;
        int res = INT_MAX;
        int len = words.size();

        for(int i = 0; i < len; i++){
            if(words[i] == target)
                arr.push_back(i);
        }

        for(int i = 0; i < arr.size(); i++){
            int dist = abs(arr[i] - startIndex);
            dist = min(dist, len - dist);
            res = min(res, dist);
        }

        return res == INT_MAX ? -1 : res;
    }
};
