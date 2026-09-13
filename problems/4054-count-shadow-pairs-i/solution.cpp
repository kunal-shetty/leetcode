// 4054. Count Shadow Pairs I
// Difficulty: Medium
// https://leetcode.com/problems/count-shadow-pairs-i/
// Runtime: 707 ms (beats —)
// Memory: 309.2 MB (beats —)
// Submitted: 2026-09-13

class Solution {
public:
    struct BIT {
        vector<int> bit;
        BIT(int n) : bit(n + 1) {}
        void add(int i) {
            i++;
            while (i < bit.size()) {
                bit[i]++;
                i += i & -i;
            }
        }
        int query(int i) {
            i++;
            int s = 0;
            while (i > 0) {
                s += bit[i];
                i -= i & -i;
            }
            return s;
        }
        int range(int l, int r){
            if(l > r) return 0;
            return query(r) - (l ? query(l - 1) : 0);
        }
    };

    struct Node { int val, idx; };
    struct Q { int val, l, r;};
    static bool compareNode(Node a, Node b){ return a.val > b.val;}
                                     static bool compareQ(Q a, Q b){
                                         return a.val > b.val;
                                     }
    long long shadowPairs(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextSmall(n, n );
        stack<int> st;
        for(int  i = n -1; i >= 0; i--){
            while(!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            if(!st.empty()) nextSmall[i] = st.top();
            st.push(i);
        }
        vector<Node> nodes(n);
        for(int i = 0; i < n; i++){
            nodes[i].val= nums[i];
            nodes[i].idx = i;
        }
            sort(nodes.begin(), nodes.end(), compareNode);
            vector<Q> q(n);
            for(int i = 0; i < n; i++){
                q[i].val = nums[i];
                q[i].l = i + 1;
                q[i].r = nextSmall[i] - 1;
                
            }
        sort(q.begin(), q.end(), compareQ);
        BIT bit(n);
        long long res = 0;
        int p = 0;
        for(int  i = 0; i < n; i++){
            while(p  < n && nodes[p].val > q[i].val){
                bit.add(nodes[p].idx);
                p++;
            }
            res += bit.range(q[i].l, q[i].r);
        }
        return res;
    }
};
