// 3296. Minimum Number of Seconds to Make Mountain Height Zero
// Difficulty: Medium
// https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/
// Runtime: 11 ms (beats —)
// Memory: 29 MB (beats —)
// Submitted: 2026-03-13

class Solution {
public:
    long long workersDone(long long time, vector<int>& workerTimes) {
        long long total = 0;

        for (int w : workerTimes) {
            long long k = (sqrt(1 + 8.0 * time / w) - 1) / 2;
            total += k;
        }

        return total;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {

        if (workerTimes.size() == 1) {
            long long w = workerTimes[0];
            return w * (long long)mountainHeight * (mountainHeight + 1) / 2;
        }

        long long left = 1;
        long long right = 1e12 * mountainHeight / workerTimes.size();

        while (left < right) {

            long long mid = left + (right - left) / 2;

            if (workersDone(mid, workerTimes) >= mountainHeight)
                right = mid;
            else
                left = mid + 1;
        }

        return left;
    }
};
