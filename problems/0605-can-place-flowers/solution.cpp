// 605. Can Place Flowers
// Difficulty: Easy
// https://leetcode.com/problems/can-place-flowers/
// Runtime: 0 ms (beats —)
// Memory: 24 MB (beats —)
// Submitted: 2026-05-29

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int safe = 0;
        int lastPlanted = -1;

        for (int i = 0; i < flowerbed.size(); i++) {
            if (flowerbed[i] == 1) {
                lastPlanted = i;
                continue;
            }

            bool left = (i - 1 < 0) || (flowerbed[i - 1] == 0 && lastPlanted != i - 1);
            bool right = (i + 1 >= flowerbed.size()) || flowerbed[i + 1] == 0;

            if (left && right) {
                safe++;
                lastPlanted = i;
            }
        }

        return safe >= n;
    }
};
