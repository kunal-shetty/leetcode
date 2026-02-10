// 142. Linked List Cycle II
// Difficulty: Medium
// https://leetcode.com/problems/linked-list-cycle-ii/
// Runtime: 0 ms (beats —)
// Memory: 11.3 MB (beats —)
// Submitted: 2026-02-10

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if (slow == fast) break;
        }
        if (!(fast && fast->next)) return NULL;
        while (head != slow) {
            head = head->next;
            slow = slow->next;
        }
        return head;
    }
};
