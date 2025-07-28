/* #2 [Medium]
https://leetcode.com/problems/add-two-numbers/

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.
You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example 1:
	Input: l1 = [2,4,3], l2 = [5,6,4]
	Output: [7,0,8]
	Explanation: 342 + 465 = 807.

Example 2:
	Input: l1 = [0], l2 = [0]
	Output: [0]

Example 3:
	Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
	Output: [8,9,9,9,0,0,0,1] 

Constraints:
	The number of nodes in each linked list is in the range [1, 100].
	0 <= Node.val <= 9
	It is guaranteed that the list represents a number that does not have leading zeros.


Runtime--> 5ms, Beats:11.05%
Memory--> 77.2MB, Beats:73.30%
Score--> 42.175%
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
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			ListNode* result = nullptr;
			ListNode* end = nullptr;
			int carry = 0;
			while (l1 != nullptr || l2 != nullptr || carry != 0) {
				int l1_num = l1 != nullptr ? l1->val : 0;
				int l2_num = l2 != nullptr ? l2->val : 0;
				int sum = l1_num + l2_num + carry;
				
				carry = sum / 10;
				int digit = sum % 10;
				
				ListNode* newNode = new ListNode(digit);
				
				if (result == nullptr) {
					result = end = newNode;
				} else {
					end->next = newNode;
					end = newNode;
				}
				if (l1) l1 = l1->next;
				if (l2) l2 = l2->next;
			}
			return result;
		}
};

ListNode* vec2List(std::vector<int> vec) {
	ListNode* result = nullptr;
	ListNode* tail = nullptr;
	for (int val : vec) {
		ListNode* newNode = new ListNode(val);
		if (result==nullptr) {
			result = tail = newNode;
		} else {
			tail->next = newNode;
			tail = newNode;
		}
	}
	return result;
}
int main() {
	std::vector<int> vec1 = {3,8,5,5,2};
	std::vector<int> vec2 = {8,6,9};
	
	ListNode* l1 = vec2List(vec1);
	ListNode* l2 = vec2List(vec2);
	
	Solution sol;
	ListNode* answer = sol.addTwoNumbers(l1, l2);
	
	std::vector<int> result;
	while (answer != nullptr) {
		result.push_back(answer->val);
		answer = answer->next;
	}
	for (int num : result) {
		printf("%d, ", num);
	}
	printf("\n");
}