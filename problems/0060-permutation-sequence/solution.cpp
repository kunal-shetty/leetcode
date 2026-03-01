// 60. Permutation Sequence
// Difficulty: Hard
// https://leetcode.com/problems/permutation-sequence/
// Runtime: 0 ms (beats —)
// Memory: 8.8 MB (beats —)
// Submitted: 2026-03-01

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> numbers;
        vector<int> fact(n, 1);
        
        for (int i = 1; i < n; i++)
            fact[i] = fact[i - 1] * i;
        
        for (int i = 1; i <= n; i++)
            numbers.push_back(i);
        
        k--; 
        string result = "";

        for (int i = n; i >= 1; i--) {
            int index = k / fact[i - 1];
            result += to_string(numbers[index]);
            numbers.erase(numbers.begin() + index);
            k %= fact[i - 1];
        }

        return result;
    }
};
