// 860. Lemonade Change
// Difficulty: Easy
// https://leetcode.com/problems/lemonade-change/
// Runtime: 0 ms (beats —)
// Memory: 87.3 MB (beats —)
// Submitted: 2026-06-17

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fives = 0, tens = 0;
        for(auto bill : bills){
            if(bill == 5) fives++;
            if(bill == 10) {
                fives--; tens++;
            }
            if(bill == 20){
                if(tens > 0) {
                    tens--; fives--;
                }
                else {
                    fives -= 3;
                }
            }
            if(fives < 0 || tens < 0) return false;
        }
        return true;
    }
};
