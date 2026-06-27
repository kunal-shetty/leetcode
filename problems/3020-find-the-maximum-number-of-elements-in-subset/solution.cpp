// 3020. Find the Maximum Number of Elements in Subset
// Difficulty: Medium
// https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/
// Runtime: 86 ms (beats —)
// Memory: 122.6 MB (beats —)
// Submitted: 2026-06-27

class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> map;

        for (int x : nums) map[x]++;

        int ans = 1;

        if (map.count(1)) {
            int c = map[1];
            ans = max(ans, c % 2 ? c : c - 1);
        }

        for (auto [num, f] : map) {
            if (num == 1) continue;

            long long x = num;
            int len = 0;

            while (map.count(x) && map[x] >= 2) {
                len += 2;

                if (x > 1e9) break; 
                x = x * x;
            }

            if (map.count(x)) len++;
            else len--;

            ans = max(ans, len);
        }

        return ans;
    }
};
