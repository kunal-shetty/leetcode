// 141. Linked List Cycle
// Difficulty: Easy
// https://leetcode.com/problems/linked-list-cycle/
// Runtime: 7 ms (beats —)
// Memory: 12 MB (beats —)
// Submitted: 2026-09-04

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == slow) return true;
        }
        return false;
    }
};
