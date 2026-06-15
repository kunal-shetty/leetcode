// 2490. Circular Sentence
// Difficulty: Easy
// https://leetcode.com/problems/circular-sentence/
// Runtime: 0 ms (beats —)
// Memory: 9.3 MB (beats —)
// Submitted: 2026-06-15

class Solution {
public:
    bool isCircularSentence(string sentence) {
        for (int i = 0; i < sentence.size(); ++i)
            if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1])
                return false;
        return sentence[0] == sentence[sentence.size() - 1];
    }
};
