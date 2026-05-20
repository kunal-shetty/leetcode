// 2657. Find the Prefix Common Array of Two Arrays
// Difficulty: Medium
// https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/
// Runtime: 7 ms (beats —)
// Memory: 86.2 MB (beats —)
// Submitted: 2026-05-20

class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> seen(n + 1, 0);
        vector<int> ans;

        int count = 0;
        for (int i = 0; i < n; i++) {
            seen[A[i]]++;
            if (seen[A[i]] == 2)
                count++;
            seen[B[i]]++;
            if (seen[B[i]] == 2)
                count++;
            ans.push_back(count);
        }
        return ans;
    }
};
