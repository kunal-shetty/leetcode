// 2095. Delete the Middle Node of a Linked List
// Difficulty: Medium
// https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
// Runtime: 3 ms (beats —)
// Memory: 312.2 MB (beats —)
// Submitted: 2026-06-15

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if (!head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = slow->next->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        slow->next = slow->next->next;
        return head;
    }
};
