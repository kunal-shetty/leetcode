// 1404. Number of Steps to Reduce a Number in Binary Representation to One
// Difficulty: Medium
// https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
// Runtime: 0 ms (beats —)
// Memory: 8.9 MB (beats —)
// Submitted: 2026-02-26

class Solution {
public:
    int numSteps(string s) {
        int count = 0;
        while (s != "1") {
            if (s.back() == '0') s.pop_back();
            else {                      
                int i = s.size() - 1;
                while (i >= 0 && s[i] == '1') {
                    s[i] = '0';
                    i--;
                }
                if (i < 0) s = '1' + s;
                else s[i] = '1';
            }
            count++;
        }
        return count;
    }
};
