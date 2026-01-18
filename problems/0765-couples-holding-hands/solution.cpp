// 765. Couples Holding Hands
// Difficulty: Hard
// https://leetcode.com/problems/couples-holding-hands/
// Runtime: 0 ms (beats —)
// Memory: 9.9 MB (beats —)
// Submitted: 2026-01-18

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int swaps = 0;
        int n = row.size();

        vector<int> position(n);
        for (int i = 0; i < n; i++) {
            position[row[i]] = i;
        }

        for (int i = 0; i < n; i += 2) {
            int first = row[i];
            int partner = first ^ 1;

            if (row[i + 1] == partner) continue;

            int partnerIndex = position[partner];

            position[row[i + 1]] = partnerIndex;
            position[partner] = i + 1;

            swap(row[i + 1], row[partnerIndex]);
            swaps++;
        }

        return swaps;
    }
};
