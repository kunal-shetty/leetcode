// 2130. Maximum Twin Sum of a Linked List
// Difficulty: Medium
// https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
// Runtime: 88 ms (beats —)
// Memory: 159.9 MB (beats —)
// Submitted: 2026-06-14

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
    ListNode* reverseCopy(ListNode* head) {
        ListNode* rev = nullptr;

        while (head) {
            ListNode* node = new ListNode(head->val);
            node->next = rev;
            rev = node;

            head = head->next;
        }

        return rev;
    }
    int pairSum(ListNode* head) {
        ListNode* reverse = reverseCopy(head);
        int maxSum = INT_MIN;
        while (head != NULL) {
            maxSum = max(maxSum, head->val + reverse->val);
            head = head->next;
            reverse = reverse->next;
        }
        return maxSum;
    }
};
