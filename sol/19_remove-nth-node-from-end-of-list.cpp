/* #19 [Medium]
https://leetcode.com/problems/remove-nth-node-from-end-of-list/

Given the head of a linked list, remove the nth node from the end of the list and return its head.

Example 1:
	Input: head = [1,2,3,4,5], n = 2
	Output: [1,2,3,5]

Example 2:
	Input: head = [1], n = 1
	Output: []

Example 3:
	Input: head = [1,2], n = 1
	Output: [1]

Runtime--> 0ms, Beats:100%
Memory--> 14.79MB, Beats:99.73%
Score--> 99.865%
*/

#include <iostream>
#include <vector>

struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode temp(0,head);
		ListNode* a = &temp;
		ListNode* b = &temp;
		
		for (int i=0; i<n; ++i) {
			a = a->next;
		}
		while (a->next) {
			a = a->next;
			b = b->next;
		}
		b->next = b->next->next;
		return temp.next;
	}
};

int main() {
	Solution sol;
	std::vector<int> nums = {1, 2};
	int rm = 2;

	// build linked list
	ListNode* head = new ListNode(nums[0]);
	ListNode* temp = head;
	for (int i = 1; i < nums.size(); i++) {
		temp->next = new ListNode(nums[i]);
		temp = temp->next;
	}

	// remove Nth node from end
	ListNode* res = sol.removeNthFromEnd(head, rm);

	// print result
	printf("Result: {");
	while (res != nullptr) {
		printf("%d", res->val);
		if (res->next) printf(",");
		res = res->next;
	}
	printf("}\n");
}