// 3302. Find the Lexicographically Smallest Valid Sequence
// Difficulty: Medium
// https://leetcode.com/problems/find-the-lexicographically-smallest-valid-sequence/
// Runtime: 51 ms (beats —)
// Memory: 115.5 MB (beats —)
// Submitted: 2026-08-08

class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int N = word1.size();
        int M = word2.size();

        int R = M - 1;
        int C = 0;
        vector<int> right(N);

        for (int i = N - 1; i >= 0; i--) {
            right[i] = C;
            if (R >= 0 && word1[i] == word2[R]) {
                R--;
                C++;
            }
        }

        vector<int> ans;
        bool changed = false;
        int j = 0;

        for (int i = 0; i < N && j < M; i++) {
            if (word1[i] == word2[j]) {
                ans.push_back(i);
                j++;
            }
            else if (!changed && right[i] >= M - 1 - j) {
                ans.push_back(i);
                j++;
                changed = true;
            }
        }

        if (j == M) return ans;
        return {};
    }
};
