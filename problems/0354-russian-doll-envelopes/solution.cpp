// 354. Russian Doll Envelopes
// Difficulty: Hard
// https://leetcode.com/problems/russian-doll-envelopes/
// Runtime: 88 ms (beats —)
// Memory: 92.3 MB (beats —)
// Submitted: 2026-09-09

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 if (a[0] == b[0])
                     return a[1] > b[1];
                 return a[0] < b[0];
             });

        int n = envelopes.size();
        vector<int> tails(n);
        int size = 0;
        for (auto envelope : envelopes) {
            int h = envelope[1];
            int left = 0;
            int right = size;

            while (left < right) {
                int mid = left + (right - left) / 2;

                if (tails[mid] < h)
                    left = mid + 1;
                else
                    right = mid;
            }

            tails[left] = h;

            if (left == size)
                size++;
        }

        return size;
    }
};
