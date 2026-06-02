// 1024. Video Stitching
// Difficulty: Medium
// https://leetcode.com/problems/video-stitching/
// Runtime: 0 ms (beats —)
// Memory: 10.5 MB (beats —)
// Submitted: 2026-06-02

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int time) {
        sort(clips.begin(), clips.end());

        int res = 0;
        int end = 0;
        int longest = 0;
        int i = 0, n = clips.size();

        while (end < time) {
            while (i < n && clips[i][0] <= end) {
                longest = max(longest, clips[i][1]);
                i++;
            }

            if (longest == end)
                return -1;

            res++;
            end = longest;
        }

        return res;
    }
};
