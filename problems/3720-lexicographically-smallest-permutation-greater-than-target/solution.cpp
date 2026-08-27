// 3720. Lexicographically Smallest Permutation Greater Than Target
// Difficulty: Medium
// https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target/
// Runtime: 0 ms (beats —)
// Memory: 9.9 MB (beats —)
// Submitted: 2026-08-27

class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        vector<int> count(26);
        for (int i = 0; i < s.size(); i++) {
            count[s[i] - 'a']++;
            count[target[i] - 'a']--;
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            int b = target[i] - 'a';
            count[b]++;  
            if (*min_element(count.begin(), count.end()) < 0) {
                continue;
            }
           
            for (int j = b + 1; j < 26; j++) {
                if (count[j]) {
                    count[j]--;
                    target[i] = 'a' + j;
                    target.resize(i + 1);
                    return target + getMinString(count);
                }
            }
        }

        return "";
    }

    string getMinString(const vector<int> count) {
        string res;
        for (int i = 0; i < 26; i++) {
            res.append(count[i], 'a' + i);
        }
        return res;
    }
};
