// 83. Remove Duplicates from Sorted List
// Difficulty: Easy
// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// Runtime: 0 ms (beats —)
// Memory: 16.3 MB (beats —)
// Submitted: 2026-03-19

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* current = head;
        while(current->next != NULL) {
            ListNode* nextNode = current->next;
            if(current->val == nextNode->val) current->next = current->next->next;
            else current = current->next;
        }
        return head;
    }
};
