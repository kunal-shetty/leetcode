// 3775. Reverse Words With Same Vowel Count
// Difficulty: Medium
// https://leetcode.com/problems/reverse-words-with-same-vowel-count/
// Runtime: 114 ms (beats —)
// Memory: 97.7 MB (beats —)
// Submitted: 2025-12-14

class Solution {
public:
    int countVowels(const string& word) {
        int count = 0;
        for (char c : word) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                count++;
        }
        return count;
    }

    string reverseString(string s) {
        reverse(s.begin(), s.end());
        return s;
    }

    string reverseWords(string s) {
        string first = "", f = "";
        vector<string> temp;

        int i = 0;
        while (i < s.length() && s[i] != ' ') {
            first += s[i];
            i++;
        }

        int count = countVowels(first);

        // FIXED word parsing
        for (int j = 0; j < s.length(); ) {
            string r = "";
            while (j < s.length() && s[j] != ' ') {
                r += s[j];
                j++;
            }
            temp.push_back(r);
            j++; // skip space
        }

        for (int k = 1; k < temp.size(); k++) {
            if (countVowels(temp[k]) == count) {
                temp[k] = reverseString(temp[k]);
            }
        }

        for (int l = 0; l < temp.size(); l++) {
            f += temp[l];
            if (l != temp.size() - 1) f += " ";
        }

        return f;
    }
};
