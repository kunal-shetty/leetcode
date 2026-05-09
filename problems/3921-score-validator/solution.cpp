// 3921. Score Validator
// Difficulty: Easy
// https://leetcode.com/problems/score-validator/
// Runtime: 3 ms (beats —)
// Memory: 53.9 MB (beats —)
// Submitted: 2026-05-09

class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;
        for(auto event : events){
            if(counter == 10) break;
            if(event == "WD" || event == "NB") score++;
            else if(event == "W") counter++;
            else score += stoi(event);
        }
        return {score, counter};
    }
};
