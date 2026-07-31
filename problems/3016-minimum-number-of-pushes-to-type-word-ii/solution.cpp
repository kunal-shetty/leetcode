// 3016. Minimum Number of Pushes to Type Word II
// Difficulty: Medium
// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/
// Runtime: 40 ms (beats —)
// Memory: 26.8 MB (beats —)
// Submitted: 2026-07-31

class Solution {
public:
    int minimumPushes(string word) {
        unordered_map<char, int> freq;

        for (char c : word) {
            freq[c]++;
        }

        priority_queue<int> heap;

        for (auto entry : freq) {
            heap.push(entry.second);
        }

        int press = 0;
        int index = 0;

        while (!heap.empty()) {
            press += (1 + (index / 8)) * heap.top();
            heap.pop();
            index++;
        }

        return press;
    }
};
