// 4015. Weighted Sum of a Tree
// Difficulty: Medium
// https://leetcode.com/problems/weighted-sum-of-a-tree/
// Runtime: 153 ms (beats —)
// Memory: 239.8 MB (beats —)
// Submitted: 2026-08-09

class Solution {
public:
    long long weightedSum(vector<int>& parent, vector<int>& nums) {
        int n = parent.size();
        vector<vector<int>> children(n);
        
        for(int i = 1; i < n; i++){
            children[parent[i]].push_back(i);
        }
        vector<int> depth(n , 0);
        queue<int> q;
        q.push(0);
        depth[0] = 1;

        int h  =1;

        while(!q.empty()){
            int u  = q.front();
            q.pop();
            h  = max(h, depth[u]);
            for(int v : children[u]){
                depth[v] = depth[u] + 1;;
                q.push(v);
            }
        }
        long long ans  = 0 ;
        for(int i = 0 ; i < n; i++){
            ans += 1LL * nums[i] * (h - depth[i] + 1);
        }
        return ans;
    }
};
