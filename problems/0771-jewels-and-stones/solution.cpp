// 771. Jewels and Stones
// Difficulty: Easy
// https://leetcode.com/problems/jewels-and-stones/
// Runtime: 0 ms (beats —)
// Memory: 8.2 MB (beats —)
// Submitted: 2026-07-18

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int count = 0;
        for(auto stone : stones){
            for(auto jewel : jewels){
                if(jewel == stone) count++;
            }
        }
        return count;
    }
};
