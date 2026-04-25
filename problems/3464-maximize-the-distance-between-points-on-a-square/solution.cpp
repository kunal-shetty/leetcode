// 3464. Maximize the Distance Between Points on a Square
// Difficulty: Hard
// https://leetcode.com/problems/maximize-the-distance-between-points-on-a-square/
// Runtime: 11 ms (beats —)
// Memory: 45.6 MB (beats —)
// Submitted: 2026-04-25

class Solution {
public:
    bool check(vector<long long>& a, int k, int side, long long d) {
        int m = a.size();
        vector<int> idx(k);

        idx[0] = 0;

        for (int i = 1; i < k; i++) {
            int j = idx[i - 1];
            while (j < m && a[j] < a[idx[i - 1]] + d)
                j++;
            if (j == m)
                return false;
            idx[i] = j;
        }

        if (a[idx[k - 1]] - a[idx[0]] <= 4LL * side - d)
            return true;

        for (idx[0] = 1; idx[0] < idx[1]; idx[0]++) {
            for (int j = 1; j < k; j++) {
                while (idx[j] < m && a[idx[j]] < a[idx[j - 1]] + d)
                    idx[j]++;
                if (idx[j] == m)
                    return false;
            }
            if (a[idx[k - 1]] - a[idx[0]] <= 4LL * side - d)
                return true;
        }
        return false;
    }

    int maxDistance(int side, vector<vector<int>>& points, int k) {
        vector<long long> a;

        for (auto& p : points) {
            int x = p[0], y = p[1];
            if (x == 0)
                a.push_back(y);
            else if (y == side)
                a.push_back(side + x);
            else if (x == side)
                a.push_back(3LL * side - y);
            else
                a.push_back(4LL * side - x);
        }

        sort(a.begin(), a.end());

        long long l = 1, r = 4LL * side / k + 1;

        while (l + 1 < r) {
            long long mid = (l + r) / 2;
            if (check(a, k, side, mid))
                l = mid;
            else
                r = mid;
        }

        return l;
    }
};
