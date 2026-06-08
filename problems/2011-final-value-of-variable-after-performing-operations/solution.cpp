// 2011. Final Value of Variable After Performing Operations
// Difficulty: Easy
// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
// Runtime: 3 ms (beats —)
// Memory: 17.7 MB (beats —)
// Submitted: 2026-06-08

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto op : operations){
            if(op.find("+") == string::npos) x--;
            else x++;
        }
        return x;
    }
};
