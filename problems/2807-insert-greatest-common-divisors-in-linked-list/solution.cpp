// 2807. Insert Greatest Common Divisors in Linked List
// Difficulty: Medium
// https://leetcode.com/problems/insert-greatest-common-divisors-in-linked-list/
// Runtime: 7 ms (beats —)
// Memory: 36.1 MB (beats —)
// Submitted: 2026-06-12

class Solution {
public:
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* curr = head;

        while (curr && curr->next) {
            int g = gcd(curr->val, curr->next->val);

            ListNode* node = new ListNode(g, curr->next);
            curr->next = node;

            curr = node->next;
        }

        return head;
    }
};
