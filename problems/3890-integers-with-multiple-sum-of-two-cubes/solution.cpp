// 3890. Integers With Multiple Sum of Two Cubes
// Difficulty: Medium
// https://leetcode.com/problems/integers-with-multiple-sum-of-two-cubes/
// Runtime: 570 ms (beats —)
// Memory: 180.2 MB (beats —)
// Submitted: 2026-04-05

class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        int tempN = n;

        unordered_map<int, int> count;

        int limit = cbrt(tempN);

        for (int a = 1; a <= limit; a++) {
            int a3 = a * a * a;

            for (int b = a; b <= limit; b++) {
                int sum = a3 + b * b * b;

                if (sum > tempN)
                    break;

                count[sum]++;
            }
        }

        vector<int> result;

        for (pair<const int, int> entry : count) {
            if (entry.second >= 2) {
                result.push_back(entry.first);
            }
        }

        sort(result.begin(), result.end());
        return result;
    }
};
