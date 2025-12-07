// 412. Fizz Buzz
// Difficulty: Easy
// https://leetcode.com/problems/fizz-buzz/
// Runtime: 0 ms (beats —)
// Memory: 11.8 MB (beats —)
// Submitted: 2025-12-07

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector <string> res;
        for(int i = 1; i <= n; i++) {
            if(i % 3 == 0 && i % 5 == 0) res.push_back("FizzBuzz");
            else if(i % 3 == 0) res.push_back("Fizz");
            else if(i % 5 == 0) res.push_back("Buzz");
            else res.push_back(to_string(i));
        }
        return res;
    }
};
