// 19. Remove Nth Node From End of List
// Difficulty: Medium
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// Runtime: 0 ms (beats —)
// Memory: 15 MB (beats —)
// Submitted: 2026-07-18

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0);
        dummy.next = head;

        ListNode* slow = &dummy;
        ListNode* fast = &dummy;

        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        while (fast) {
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* temp = slow->next;
        slow->next = slow->next->next;

        return dummy.next;
    }
};
