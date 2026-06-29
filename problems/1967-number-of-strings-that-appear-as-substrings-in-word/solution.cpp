// 1967. Number of Strings That Appear as Substrings in Word
// Difficulty: Easy
// https://leetcode.com/problems/number-of-strings-that-appear-as-substrings-in-word/
// Runtime: 0 ms (beats —)
// Memory: 12.1 MB (beats —)
// Submitted: 2026-06-29

class Solution {
public:
    bool needleInHaystack(string needle, string haystack) {
        int k = needle.size();

        for (int left = 0, right = k - 1; right < haystack.size();
             left++, right++) {

            bool found = true;

            for (int i = 0; i < k; i++) {
                if (haystack[left + i] != needle[i]) {
                    found = false;
                    break;
                }
            }

            if (found)
                return true;
        }

        return false;
    }

    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0;

        for (string& pattern : patterns) {
            if (needleInHaystack(pattern, word))
                count++;
        }
        return count;
    }
};
