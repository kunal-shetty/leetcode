// 3960. Frequency Balance Subarray
// Difficulty: Medium
// https://leetcode.com/problems/frequency-balance-subarray/
// Runtime: 1637 ms (beats —)
// Memory: 473 MB (beats —)
// Submitted: 2026-06-14

class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            unordered_map<int, int> freq;
            unordered_map<int, int> count;
            int maxVal = 0;

            for (int j = i; j < n; j++) {
                int x = nums[j];

                if (freq[x] > 0) {
                    count[freq[x]]--;
                    if (count[freq[x]] == 0)
                        count.erase(freq[x]);
                }
                freq[x]++;
                count[freq[x]]++;

                maxVal = max(maxVal, freq[x]);

                if (freq.size() == 1) {
                    ans = max(ans, j - i + 1);
                    continue;
                }

                if (maxVal % 2)
                    continue;
                int half = maxVal / 2;
                bool valid = true;

                for (auto entry : count) {
                    if (entry.first != maxVal && entry.first != half) {
                        valid = false;
                        break;
                    }
                }

                if (valid && count.count(maxVal) && count.count(half))
                    ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
