// 3525. Find X Value of Array II
// Difficulty: Hard
// https://leetcode.com/problems/find-x-value-of-array-ii/
// Runtime: 393 ms (beats —)
// Memory: 310.5 MB (beats —)
// Submitted: 2026-09-22

struct SegmentTree {
    struct Node {
        int prod;
        int count[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                count[i] = 0;
        }
    };

    int n, k;
    vector<Node> tree;

    SegmentTree(vector<int>& nums, int K) {
        n = nums.size();
        k = K;
        tree.resize(4 * n);
        build(1, 0, n - 1, nums);
    }

    Node merge(const Node &left, const Node &right) {
        Node result;

        result.prod = (left.prod * right.prod) % k;

        for (int i = 0; i < k; i++)
            result.count[i] = left.count[i];

        for (int i = 0; i < k; i++) {
            int rem = (i * left.prod) % k;
            result.count[rem] += right.count[i];
        }

        return result;
    }

    void build(int node, int left, int right, vector<int>& nums) {
        if (left == right) {
            int value = nums[left] % k;
            tree[node].prod = value;
            tree[node].count[value] = 1;
            return;
        }

        int mid = (left + right) / 2;
        build(node * 2, left, mid, nums);
        build(node * 2 + 1, mid + 1, right, nums);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    void update(int node, int left, int right, int index, int value) {
        if (left == right) {
            value %= k;
            tree[node] = Node();
            tree[node].prod = value;
            tree[node].count[value] = 1;
            return;
        }

        int mid = (left + right) / 2;

        if (index <= mid)
            update(node * 2, left, mid, index, value);
        else
            update(node * 2 + 1, mid + 1, right, index, value);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }

    Node query(int node, int left, int right, int QL, int QR) {
        if (QL <= left && right <= QR)
            return tree[node];

        int mid = (left + right) / 2;

        if (QR <= mid)
            return query(node * 2, left, mid, QL, QR);

        if (QL > mid)
            return query(node * 2 + 1, mid + 1, right, QL, QR);

        Node resL = query(node * 2, left, mid, QL, QR);
        Node resR = query(node * 2 + 1, mid + 1, right, QL, QR);

        return merge(resL, resR);
    }
};

class Solution {
public:
    vector<int> resultArray(vector<int>& nums, int k, vector<vector<int>>& queries) {
        SegmentTree segmentTree(nums, k);
        vector<int> res;

        for (auto query : queries) {
            int index = query[0];
            int value = query[1];
            int start = query[2];
            int x = query[3];

            segmentTree.update(1, 0, segmentTree.n - 1, index, value);

            auto suffixInfo = segmentTree.query(1, 0, segmentTree.n - 1, start, segmentTree.n - 1);
            res.push_back(suffixInfo.count[x]);
        }

        return res;
    }
};
