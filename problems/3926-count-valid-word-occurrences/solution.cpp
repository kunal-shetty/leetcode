// 3926. Count Valid Word Occurrences
// Difficulty: Medium
// https://leetcode.com/problems/count-valid-word-occurrences/
// Runtime: 115 ms (beats —)
// Memory: 239.9 MB (beats —)
// Submitted: 2026-05-10

class Solution {
public:
    bool isLetter(char c) {
        return c >= 'a' && c <= 'z';
    }

    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {
        string text;

        for(string chunk : chunks)
            text += chunk;

        unordered_map<string,int> freq;

        int n = text.size();
        int i = 0;

        while(i < n) {
            string word;

            while(i < n) {
                if(isLetter(text[i])) {
                    word += text[i];
                }
                else if(text[i] == '-' &&
                        i > 0 &&
                        i + 1 < n &&
                        isLetter(text[i - 1]) &&
                        isLetter(text[i + 1])) {
                    word += '-';
                }
                else {
                    break;
                }

                i++;
            }

            if(!word.empty())
                freq[word]++;

            i++;
        }

        vector<int> answer;

        for(string query : queries)
            answer.push_back(freq[query]);

        return answer;
    }
};
