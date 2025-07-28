/* #1 [Easy]
https://leetcode.com/problems/two-sum/

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:
	Input: nums = [2,7,11,15], target = 9
	Output: [0,1]
	Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

Example 2:
	Input: nums = [3,2,4], target = 6
	Output: [1,2]

Example 3:
	Input: nums = [3,3], target = 6
	Output: [0,1]

Runtime--> 82ms, Beats:13.28%
Memory--> 14.08MB, Beats:78.50%
Score--> 45.89%
*/

#include <iostream>
#include <vector>

class Solution {
	public:
		std::vector<int> twoSum(std::vector<int> &nums, int target) {
			int size = nums.size();
			for (int j=0; j<size; j++) {
				for (int i=0; i<size && j!=i; i++) {
					if (nums[i] + nums[j] == target) {
						return {i,j};
					}
				}
			};
			return {0,0};
		};
};

int main() {
	Solution sol;
	std::vector<int> nums = {7,5,9,1,4};
	std::vector<int> res = sol.twoSum(nums, 11);
	printf("Result: [%i,%i]", res[0], res[1]);
}