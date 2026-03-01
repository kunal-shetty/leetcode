// 160. Intersection of Two Linked Lists
// Difficulty: Easy
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// Runtime: 54 ms (beats —)
// Memory: 24.1 MB (beats —)
// Submitted: 2026-03-01

class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *ptr1 = headA;
		ListNode *ptr2 = headB;
		while(ptr1 != ptr2){
			if(ptr1 == NULL) ptr1 = headB;
			else ptr1 = ptr1 -> next;
			if(ptr2 == NULL) ptr2 = headA;
			else ptr2 = ptr2 -> next;
		}
		return ptr1;
	}
};
