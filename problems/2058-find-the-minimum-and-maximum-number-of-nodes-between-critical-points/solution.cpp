// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points
// Difficulty: Medium
// https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
// Runtime: 4 ms (beats —)
// Memory: 124.7 MB (beats —)
// Submitted: 2026-08-31

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;
        int last = -1;
        int i = 1;
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        while(curr->next != nullptr) {
            if((curr->val > prev->val && curr->val > curr->next->val) ||
               (curr->val < prev->val && curr->val < curr->next->val)) {

                if(first == -1) {
                    first = i;
                    last = i;
                }
                else {
                    minDist = min(minDist, i - last);
                    last = i;
                }
            }

            prev = curr;
            curr = curr->next;
            i++;
        }

        if(first == last)
            return {-1, -1};

        return {minDist, last - first};
    }
};
