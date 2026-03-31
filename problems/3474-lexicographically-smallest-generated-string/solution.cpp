// 3474. Lexicographically Smallest Generated String
// Difficulty: Hard
// https://leetcode.com/problems/lexicographically-smallest-generated-string/
// Runtime: 44 ms (beats —)
// Memory: 11.1 MB (beats —)
// Submitted: 2026-03-31

class Solution {
public:
    string generateString(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        string res(n + m - 1, 'a');
        vector<bool> locked(n + m - 1);

        for (int i = 0; i < n; i++)
            if (s1[i] == 'T')
                for (int j = 0; j < m; j++)
                    res[i + j] = s2[j], locked[i + j] = true;

        for (int i = 0; i < n; i++) {
            bool match = true;
            for (int j = 0; j < m; j++)
                if (res[i + j] != s2[j]) { match = false; break; }

            if (s1[i] == 'F' && match)
                for (int j = m - 1; j >= 0; j--)
                    if (!locked[i + j]) { res[i + j] = 'b'; break; }

            if (s1[i] == 'T' && !match) return "";
        }

        for (int i = 0; i < n; i++) {
            bool match = true;
            for (int j = 0; j < m; j++)
                if (res[i + j] != s2[j]) { match = false; break; }

            if ((s1[i] == 'T' && !match) || (s1[i] == 'F' && match))
                return "";
        }

        return res;
    }
};
