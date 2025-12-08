// 4. Median of Two Sorted Arrays
// Difficulty: Hard
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Runtime: 0 ms (beats —)
// Memory: 95.8 MB (beats —)
// Submitted: 2025-12-08

class Solution {
public:
    vector<int> mergeArrays(const vector<int>& a, const vector<int>& b) {
    vector<int> c;
    int i = 0, j = 0;

    while (i < a.size() && j < b.size()) {
        if (a[i] < b[j])
            c.push_back(a[i++]);
        else
            c.push_back(b[j++]);
    }

    // push remaining elements
    while (i < a.size()) c.push_back(a[i++]);
    while (j < b.size()) c.push_back(b[j++]);

    return c;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> num3 = mergeArrays(nums1, nums2);
        int l = num3.size();
        if(l % 2) return num3[l / 2];
        double res =  (num3[(l / 2 - 1)] + num3[(l / 2)]) / 2.0;
        return res;
    }
};
