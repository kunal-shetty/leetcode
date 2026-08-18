// 2125. Number of Laser Beams in a Bank
// Difficulty: Medium
// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
// Runtime: 9 ms (beats —)
// Memory: 33.1 MB (beats —)
// Submitted: 2026-08-18

class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0, count = 0;
        for (string s : bank) {
            count = 0;
            for (int i = 0; i < s.size(); i++)
                if (s[i] == '1')
                    count++;
            if (count) {
                ans += prev * count;
                prev = count;
            }
        }
        return ans;
    }
};
