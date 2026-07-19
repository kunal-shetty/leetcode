// 3999. Minimum Number of String Groups Through Transformations
// Difficulty: Hard
// https://leetcode.com/problems/minimum-number-of-string-groups-through-transformations/
// Runtime: 292 ms (beats —)
// Memory: 213.1 MB (beats —)
// Submitted: 2026-07-19

class Solution {
public:
    string minRotate(string s) {
        int n = s.size();
        if (n <= 1)
            return s;
        string t = s + s;
        int i = 0, j = 1, k = 0;
        while (i < n && j < n && k < n) {
            if (t[i + k] == t[j + k]) {
                k++;
            } else if (t[i + k] > t[j + k]) {
                i += k + 1;
                if (i <= j)
                    i = j + 1;
                k = 0;

            } else {
                j += k + 1;
                if (j <= i)
                    j = i + 1;
                k = 0;
            }
        }
        int st = min(i, j);
        return t.substr(st, n);
    }

    int minimumGroups(vector<string>& words) {
        unordered_set<string> set;
        for (auto word : words) {
            string even = "", odd = "";
            for (int i = 0; i < word.size(); i++) {
                if (i % 2 == 0)
                    even += word[i];
                else
                    odd += word[i];
            }
            string key = minRotate(even) + "#" + minRotate(odd);
            set.insert(key);
        }
        return set.size();
    }
};
