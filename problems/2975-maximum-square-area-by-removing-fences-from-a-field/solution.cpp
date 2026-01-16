// 2975. Maximum Square Area by Removing Fences From a Field
// Difficulty: Medium
// https://leetcode.com/problems/maximum-square-area-by-removing-fences-from-a-field/
// Runtime: 1010 ms (beats —)
// Memory: 250.2 MB (beats —)
// Submitted: 2026-01-16

class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences,
                           vector<int>& vFences) {
        const int MOD = 1e9 + 7;

        // Add boundaries
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);

        sort(hFences.begin(), hFences.end());
        sort(vFences.begin(), vFences.end());

        vector<int> hDist, vDist;

        // All horizontal distances
        for (int i = 0; i < hFences.size(); i++) {
            for (int j = i + 1; j < hFences.size(); j++) {
                hDist.push_back(hFences[j] - hFences[i]);
            }
        }

        // All vertical distances
        for (int i = 0; i < vFences.size(); i++) {
            for (int j = i + 1; j < vFences.size(); j++) {
                vDist.push_back(vFences[j] - vFences[i]);
            }
        }

        // Sort distances
        sort(hDist.begin(), hDist.end());
        sort(vDist.begin(), vDist.end());

        // Two pointers to find largest common distance
        int i = hDist.size() - 1;
        int j = vDist.size() - 1;
        int maxDist = -1;

        while (i >= 0 && j >= 0) {
            if (hDist[i] == vDist[j]) {
                maxDist = hDist[i];
                break;
            } else if (hDist[i] > vDist[j]) {
                i--;
            } else {
                j--;
            }
        }

        if (maxDist == -1) return -1;

        long long side = maxDist - 1;
        return (side + 1) * (side + 1) % MOD;
    }
};
