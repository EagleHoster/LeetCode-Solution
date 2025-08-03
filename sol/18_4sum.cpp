/* #18 [Medium]
https://leetcode.com/problems/4sum/

Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

0 <= a, b, c, d < n
a, b, c, and d are distinct.
nums[a] + nums[b] + nums[c] + nums[d] == target
You may return the answer in any order.


Example 1:
	Input: nums = [1,0,-1,0,-2,2], target = 0
	Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

Example 2:
	Input: nums = [2,2,2,2,2], target = 8
	Output: [[2,2,2,2]]

Runtime--> 15ms, 92.77Beats:%
Memory--> 17.53MB, Beats:29.07%
Score--> %
*/

#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
	public:
		std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
			std::vector<std::vector<int>> result = {};
			std::sort(nums.begin(), nums.end());
			int s = nums.size();
			long long tar = 0;
			int left = 0;
			int right = 0;
			long long add = 0;
			
			for (int i=0; i<s-3; i++) {
				if (i>0 && nums[i] == nums[i-1]) continue;
				for (int j=i+1; j<s-2; j++) {
					if (j>i+1 && nums[j] == nums[j-1]) continue;
					tar = (long long)target - (long long)nums[i] - (long long)nums[j];
					
					left = j+1;
					right = s-1;
					while (left < right) {
						add = (long long)nums[left] + (long long)nums[right];
						if (add == tar) {
							result.push_back({nums[i], nums[j], nums[left], nums[right]});
							while (left < right && nums[left] == nums[left + 1]) left++;
							while (left < right && nums[right] == nums[right - 1]) right--;
							left++;
							right--;
						}
						if (add < tar) {
							left++;
						} else {
							right--;
						}
					}
				}
			}
			return result;
		}
};

int main() {
	Solution sol;
	std::vector<int> nums = {1000000000,1000000000,1000000000,1000000000};
	int target = -294967296;
	std::vector<std::vector<int>> res = sol.fourSum(nums, target);
	
	if (res.size()) {
		printf("Result: \n");
		for (std::vector<int> r : res) {
			printf("\t{%d, %d, %d, %d}\n", r[0], r[1], r[2], r[3]);
		}
	}
}