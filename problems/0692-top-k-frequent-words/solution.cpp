// 692. Top K Frequent Words
// Difficulty: Medium
// https://leetcode.com/problems/top-k-frequent-words/
// Runtime: 4 ms (beats —)
// Memory: 18.1 MB (beats —)
// Submitted: 2026-09-22

class Solution {
public:
    struct compare {
        bool operator()(pair<int, string>& a, pair<int, string>& b) {
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        }
    };

    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        priority_queue<pair<int, string>, vector<pair<int, string>>, compare> heap;
        for (auto word : words)
            freq[word]++;

        for (auto [s, f] : freq)
            heap.push({f, s});

        vector<string> res;
        while (k) {
            res.push_back(heap.top().second);
            heap.pop();
            k--;
        }

        return res;
    }
};
