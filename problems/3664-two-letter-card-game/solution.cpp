// 3664. Two-Letter Card Game
// Difficulty: Medium
// https://leetcode.com/problems/two-letter-card-game/
// Runtime: 36 ms (beats —)
// Memory: 276.1 MB (beats —)
// Submitted: 2026-10-07

class Solution {
public:
    int maxPairs(int total, int largest, int xx) {
        if (!total) return 0;
        int rem = total - largest;
        if (largest <= rem) {
            int b = total / 2, odd = total % 2;
            int used = min(xx, odd);
            return b + used + min((xx - used) / 2, b);
        }
        int used = min(xx, largest - rem);
        return rem + used + min((xx - used) / 2, rem);
    }

    int score(vector<string>& cards, char x) {
        int xx = 0;
        vector<int> xy(26, 0), yx(26, 0);

        for (auto card : cards) {
            if (card[0] == x && card[1] == x) xx++;
            else if (card[0] == x) xy[card[1] - 'a']++;
            else if (card[1] == x) yx[card[0] - 'a']++;
        }

        int totalXY = 0, maxXY = 0;
        for (auto c : xy) { totalXY += c; maxXY = max(maxXY, c); }

        int totalYX = 0, maxYX = 0;
        for (auto c : yx) { totalYX += c; maxYX = max(maxYX, c); }

        int res = 0;
        for (int i = 0; i <= min(xx, totalXY); i++)
            res = max(res, maxPairs(totalXY, maxXY, i) + maxPairs(totalYX, maxYX, xx - i));

        return res;
    }
};
