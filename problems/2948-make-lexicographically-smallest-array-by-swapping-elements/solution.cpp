// 2948. Make Lexicographically Smallest Array by Swapping Elements
// Difficulty: Medium
// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements/
// Runtime: 352 ms (beats —)
// Memory: 234.1 MB (beats —)
// Submitted: 2026-08-29

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& arr, int limit) {
        vector<int> sortArr = arr;
        sort(sortArr.begin(), sortArr.end());

        unordered_map<int, int> numGrp;
        unordered_map<int, list<int>> grpList;
        int grp = 0;

        numGrp[sortArr[0]] = grp;
        grpList[grp].push_back(sortArr[0]);

        for (int i = 1; i < sortArr.size(); i++) {
            if (sortArr[i] - sortArr[i - 1] > limit) grp++;
            numGrp[sortArr[i]] = grp;
            grpList[grp].push_back(sortArr[i]);
        }

        for (int i = 0; i < arr.size(); i++) {
            int grp = numGrp[arr[i]];
            arr[i] = grpList[grp].front();
            grpList[grp].pop_front();
        }

        return arr;
    }
};
