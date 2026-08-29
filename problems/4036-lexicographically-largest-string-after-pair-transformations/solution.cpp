// 4036. Lexicographically Largest String After Pair Transformations
// Difficulty: Medium
// https://leetcode.com/problems/lexicographically-largest-string-after-pair-transformations/
// Runtime: 102 ms (beats —)
// Memory: 206.1 MB (beats —)
// Submitted: 2026-08-29

class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> res;
        int Z = 1 << 25;
        for (auto num : nums) {
            string s = "";
            while(num >= Z){
                s += 'z';
                num -= Z;
            }
            for (int i = 24; i >= 0; i--) {
                if (num & (1 << i))
                    s += char('a' + i);
            }
            res.push_back(s);
        }
        return res;
    }
};
