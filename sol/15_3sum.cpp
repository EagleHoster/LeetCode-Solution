/* #15 [Medium]
https://leetcode.com/problems/3sum/

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

Example 1:
	Input: nums = [-1,0,1,2,-1,-4]
	Output: [[-1,-1,2],[-1,0,1]]
	Explanation: 
	nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
	nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
	nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
	The distinct triplets are [-1,0,1] and [-1,-1,2].
	Notice that the order of the output and the order of the triplets does not matter.

Example 2:
	Input: nums = [0,1,1]
	Output: []
	Explanation: The only possible triplet does not sum up to 0.

Example 3:
	Input: nums = [0,0,0]
	Output: [[0,0,0]]
	Explanation: The only possible triplet sums up to 0.

Runtime--> 43ms, Beats:86.39%
Memory--> 29.16MB, Beats:49.84%
Score--> 68.115%
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
	public:
		std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
			std::sort(nums.begin(), nums.end());
			std::vector<std::vector<int>> res = {};
			int left = 0, right = 0;
			for (int i=0; i<nums.size(); i++) {
				if (i>0 && nums[i] == nums[i-1]) continue;
				left = i+1;
				right = nums.size()-1;
				while (left < right) {
					int sum = nums[i] + nums[left] + nums[right];
					if (sum == 0) {
						//if (nums[i] != nums[left] && nums[i] != nums[right]) {
							res.push_back({nums[i], nums[left], nums[right]});
						//};
						left++;
						right--;
						while (left < right && nums[left] == nums[left-1]) left++;
						while (left < right && nums[right] == nums[right+1]) right--;
						continue;
					} else if (sum < 0) {
						left++;
						continue;
					} else if (sum > 0) {
						right--;
						continue;
					}
				}
			}
			return res;
		}
};

int main() {
	Solution sol;
	std::vector<int> nums = {-1,0,1,2,-1,-4};
	std::vector<std::vector<int>> res = sol.threeSum(nums);
	printf("Result: {\n");
	for (int i=0; i<res.size(); i++) {
		printf("\t{");
		for (int j=0; j<res[i].size(); j++) {
			printf("%d,", res[i][j]);
		}
		printf("}\n");
	}
	printf("}\n");
}