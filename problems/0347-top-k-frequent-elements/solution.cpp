// 347. Top K Frequent Elements
// Difficulty: Medium
// https://leetcode.com/problems/top-k-frequent-elements/
// Runtime: 3 ms (beats —)
// Memory: 18.1 MB (beats —)
// Submitted: 2026-09-02

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto num : nums){
            freq[num]++;
        }
        priority_queue<pair<int, int>> heap;
        vector<int> res;
        for(auto entry : freq){
            heap.push({entry.second, entry.first});
        }
        while(k){
            res.push_back(heap.top().second);
            k--;
            heap.pop();
        }
        return res;
    }
};
