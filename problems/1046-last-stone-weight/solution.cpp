// 1046. Last Stone Weight
// Difficulty: Easy
// https://leetcode.com/problems/last-stone-weight/
// Runtime: 0 ms (beats —)
// Memory: 9.9 MB (beats —)
// Submitted: 2026-09-08

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
       priority_queue<int> heap;
       for(auto stone : stones){
        heap.push(stone);
       } 
       while(!heap.empty()){
        if(heap.size() == 1) return heap.top();
        int s1 = heap.top();
        heap.pop();
        int s2 = heap.top();
        heap.pop();
        if(s1 == s2) continue;
        else {
            heap.push(abs(s1 - s2));
        }
       }
       return 0;
    }
};
