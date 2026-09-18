// 506. Relative Ranks
// Difficulty: Easy
// https://leetcode.com/problems/relative-ranks/
// Runtime: 0 ms (beats —)
// Memory: 15.6 MB (beats —)
// Submitted: 2026-09-18

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();

        priority_queue<pair<int, int>> heap;
        for (int i = 0; i < n; i++) {
            heap.push({score[i], i});
        }

        vector<string> rank(n);
        int place = 1;
        while (!heap.empty()) {
            int i = heap.top().second;
            heap.pop();
            if (place == 1) {
                rank[i] = "Gold Medal";
            } else if (place == 2) {
                rank[i] = "Silver Medal";
            } else if (place == 3) {
                rank[i] = "Bronze Medal";
            } else {
                rank[i] = to_string(place);
            }
            place++;
        }
        return rank;
    }
};
