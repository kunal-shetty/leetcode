// 345. Reverse Vowels of a String
// Difficulty: Easy
// https://leetcode.com/problems/reverse-vowels-of-a-string/
// Runtime: 0 ms (beats —)
// Memory: 10.3 MB (beats —)
// Submitted: 2026-05-03

class Solution {
public:
    bool isVowel(char c){
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }

    string reverseVowels(string s) {
        int start = 0, end = s.length() - 1;

        while(start < end){
            if(!isVowel(s[start])) {
                start++;
            }
            else if(!isVowel(s[end])) {
                end--;
            }
            else {
                swap(s[start], s[end]);
                start++;
                end--;
            }
        }
        return s;
    }
};
