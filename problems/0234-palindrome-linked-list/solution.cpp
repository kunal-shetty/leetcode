// 234. Palindrome Linked List
// Difficulty: Easy
// https://leetcode.com/problems/palindrome-linked-list/
// Runtime: 11 ms (beats —)
// Memory: 126.6 MB (beats —)
// Submitted: 2026-05-03

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
    bool isPalindrome(ListNode* head) {
        string num = "";
        while(head != NULL){
            num += head->val;
            head = head->next;
        }
        string rev = num;
        reverse(num.begin(), num.end());
        return rev == num;
    }
};
