// 3886. Sum of Sortable Integers
// Difficulty: Hard
// https://leetcode.com/problems/sum-of-sortable-integers/
// Runtime: 23 ms (beats 91.2%)
// Memory: 98.1 MB (beats 34.6%)
// Submitted: 2026-10-20

class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size(), res = 0;
        vector<int> desc(n), prefMax(n), suffMin(n);

        for (int i = 0; i < n; i++) {
            prefMax[i] = suffMin[i] = nums[i];
            if (i > 0)
                desc[i] = desc[i - 1] + (nums[i - 1] > nums[i]);
        }

        for (int i = 1; i < n; i++)
            prefMax[i] = max(prefMax[i], prefMax[i - 1]);

        for (int i = n - 2; i >= 0; i--)
            suffMin[i] = min(suffMin[i], suffMin[i + 1]);

        vector<bool> split(n, true);
        for (int i = 1; i < n; i++)
            split[i] = prefMax[i - 1] <= suffMin[i];

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool ok = true;
            for (int i = 0; i < n; i += k) {
                int l = i, r = i + k - 1;
                int descents = desc[r] - desc[l] + (nums[r] > nums[l]);

                if (!split[l] || descents > 1) {
                    ok = false;
                    break;
                }
            }

            if (ok) res += k;
        }

        return res;
    }
};
