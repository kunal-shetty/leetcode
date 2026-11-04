// 3505. Minimum Operations to Make Elements Within K Subarrays Equal
// Difficulty: Hard
// https://leetcode.com/problems/minimum-operations-to-make-elements-within-k-subarrays-equal/
// Runtime: 438 ms (beats 100.0%)
// Memory: 220.5 MB (beats 96.9%)
// Submitted: 2026-11-04

class Fenwick {
    int n;
    vector<long long> count, sum;

public:
    Fenwick(int size) : n(size), count(size + 1, 0), sum(size + 1, 0) {}

    void update(int index, int freq, long long val) {
        while (index <= n) {
            count[index] += freq;
            sum[index] += val;
            index += index & -index;
        }
    }

    long long query(vector<long long>& bit, int index) {
        long long res = 0;
        while (index > 0) {
            res += bit[index];
            index -= index & -index;
        }
        return res;
    }

    int kth(int k) {
        int pos = 0;

        int step = 1;
        while (step <= n) {
            step <<= 1;
        }
        step >>= 1;

        while (step) {
            if (pos + step <= n && count[pos + step] < k) {
                pos += step;
                k -= count[pos];
            }
            step >>= 1;
        }

        return pos + 1;
    }

    long long queryCount(int index) {
        return query(count, index);
    }

    long long querySum(int index) {
        return query(sum, index);
    }
};

class Solution {
public:
    long long minOperations(vector<int>& nums, int windowSize, int k) {
        int n = nums.size();

        vector<int> values = nums;
        sort(values.begin(), values.end());
        values.erase(unique(values.begin(), values.end()), values.end());

        int m = values.size();
        Fenwick bit(m);

        vector<int> rank(n);
        for (int i = 0; i < n; i++)
            rank[i] = lower_bound(values.begin(), values.end(), nums[i])
                      - values.begin() + 1;

        long long windowSum = 0;       
        int medianPos = (windowSize + 1) / 2; 

        for (int i = 0; i < windowSize; i++) {
            bit.update(rank[i], 1, nums[i]);
            windowSum += nums[i];
        }

        vector<long long> cost(n - windowSize + 1);

        for (int i = 0; i + windowSize <= n; i++) {
            int r = bit.kth(medianPos);
            long long medVal = values[r - 1]; 

            long long leftCount = bit.queryCount(r);
            long long leftSum = bit.querySum(r);

            cost[i] = medVal * leftCount - leftSum
                    + (windowSum - leftSum)
                    - medVal * (windowSize - leftCount);

            bit.update(rank[i], -1, -nums[i]);
            windowSum -= nums[i];

            if (i + windowSize < n) {
                bit.update(rank[i + windowSize], 1, nums[i + windowSize]);
                windowSum += nums[i + windowSize];
            }
        }

        const long long INF = LLONG_MAX / 4;
        vector<long long> prev(n + 1, 0), curr(n + 1, INF);

        for (int i = 1; i <= k; i++) {
            fill(curr.begin(), curr.end(), INF);

            for (int j = windowSize; j <= n; j++) {
                curr[j] = curr[j - 1];

                if (prev[j - windowSize] < INF)
                    curr[j] = min(curr[j],
                                  prev[j - windowSize] + cost[j - windowSize]);
            }

            swap(prev, curr);
        }

        return prev[n];
    }
};
