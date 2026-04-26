// 3913. Sort Vowels by Frequency
// Difficulty: Medium
// https://leetcode.com/problems/sort-vowels-by-frequency/
// Runtime: 159 ms (beats —)
// Memory: 18.4 MB (beats —)
// Submitted: 2026-04-26

class Solution {
public:
    bool isVowel(char c) {
        return c=='a'||c=='e'||c=='i'||c=='o'||c=='u';
    }

    string sortVowels(string s) {
        unordered_map<char, int> freq;
        unordered_map<char, int> firstPos;
        vector<char> vowels;

        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                vowels.push_back(s[i]);
                freq[s[i]]++;
                if(!firstPos.count(s[i])) firstPos[s[i]] = i;
            }
        }

        sort(vowels.begin(), vowels.end(), [&](char a, char b){
            if(freq[a] == freq[b])
                return firstPos[a] < firstPos[b];
            return freq[a] > freq[b];
        });

        int idx = 0;
        for(int i = 0; i < s.size(); i++){
            if(isVowel(s[i])){
                s[i] = vowels[idx++];
            }
        }

        return s;
    }
};
