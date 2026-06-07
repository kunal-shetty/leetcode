// 3955. Valid Binary Strings With Cost Limit
// Difficulty: Medium
// https://leetcode.com/problems/valid-binary-strings-with-cost-limit/
// Runtime: 195 ms (beats —)
// Memory: 119.8 MB (beats —)
// Submitted: 2026-06-07

class Solution {
public:
    void generate(int i, int n, string curr, vector<string>& all) {
        if (i == n) {
            all.push_back(curr);
            return;
        }
        curr.push_back('0');
        generate(i + 1, n, curr, all);
        curr.pop_back();

        curr.push_back('1');
        generate(i + 1, n, curr, all);
        curr.pop_back();
    }
    vector<string> generateValidStrings(int n, int k) {
        vector<string> all;
        string curr;
        generate(0, n, curr, all);
        vector<string> res;
        for (auto s : all) {
            if (s.find("11") != string::npos)
                continue;
            int cost = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '1')
                    cost += i;
            }
            if (cost > k)
                continue;
            res.push_back(s);
        }
        return res;
    }
};
