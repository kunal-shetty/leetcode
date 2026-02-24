// 43. Multiply Strings
// Difficulty: Medium
// https://leetcode.com/problems/multiply-strings/
// Runtime: 5 ms (beats —)
// Memory: 10.7 MB (beats —)
// Submitted: 2026-02-24

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";

        int n = num1.size();
        int m = num2.size();
        vector<int> result(n + m, 0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int mul = (num1[i] - '0') * (num2[j] - '0');
                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;     
                result[i + j] += sum / 10;         
            }
        }

        string ans = "";
        for (int num : result) {
            if (!(ans.empty() && num == 0)) { 
                ans += to_string(num);
            }
        }

        return ans.empty() ? "0" : ans;
    }
};
