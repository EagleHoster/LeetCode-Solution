/* #21 [Easy]
https://leetcode.com/problems/merge-two-sorted-lists/

You are given the heads of two sorted linked lists list1 and list2.
Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]

Example 2:
Input: list1 = [], list2 = []
Output: []

Example 3:
Input: list1 = [], list2 = [0]
Output: [0]

Runtime--> 0ms, Beats:100%
Memory--> 19.66MB, Beats:11.32%
Score--> 55.66%
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

std::vector<int> lList2Arr(ListNode *head) {
	std::vector<int> result = {};
	ListNode *Head = head;
	
	while (Head != nullptr) {
		result.push_back(Head->val);
		Head = Head->next;
	}
	return result;
}

ListNode* Arr2lList(std::vector<int> l) {
	ListNode *head = new ListNode(l[0]);
	ListNode *temp = head;
	for (int i=1; i<l.size(); i++) {
		ListNode *node = new ListNode(l[i]);
		temp->next = node;
		temp = node;
	}
	return head;
}

class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
			ListNode res(0);
			ListNode *temp = &res;
			while (list1 && list2) {
				if (list1->val < list2->val) {
					temp->next = new ListNode(list1->val);
					list1 = list1->next;
				} else if (list1->val > list2->val) {
					temp->next = new ListNode(list2->val);
					list2 = list2->next;
				} else {
					temp->next = new ListNode(list1->val);
					temp = temp->next;
					temp->next = new ListNode(list2->val);
					list1 = list1->next;
					list2 = list2->next;
				}
				temp = temp->next;
			}
			while (list1) {
				temp->next = new ListNode(list1->val);
				temp = temp->next;
				list1 = list1->next;
			}
			
			while (list2) {
				temp->next = new ListNode(list2->val);
				temp = temp->next;
				list2 = list2->next;
			}
			return res.next;
		}
};

int main() {
	Solution sol;
	std::vector<int> num = {1,2,4};
	std::vector<int> num2 = {1,3,4};
	ListNode *l1 = Arr2lList(num);
	ListNode *l2 = Arr2lList(num2);
	ListNode *LN = sol.mergeTwoLists(l1, l2);
	std::vector<int> res = lList2Arr(LN);
	printf("Result: {");
	for (int i=0; i<res.size(); i++) {
		printf("%d,", res[i]);
	}
	printf("}\n");
}