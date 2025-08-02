/* #16 [Medium]
https://leetcode.com/problems/3sum-closest/

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.

Example 1:
	Input: nums = [-1,2,1,-4], target = 1
	Output: 2
	Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
	Input: nums = [0,0,0], target = 1
	Output: 0
	Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).

Runtime--> 17ms, Beats:24.38%
Memory--> 14.11MB, Beats:28.41%
Score--> 26.395%
*/

#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    int threeSumClosest(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int closest = nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                
                if (abs(sum - target) < abs(closest - target)) {
                    closest = sum;
                }

                if (sum == target) {
                    return target;
                } else if (sum < target) {
                    left++;
                } else {
                    right--;
                }
            }
        }

        return closest;
    }
};

int main() {
	Solution sol;
	std::vector<int> nums = {-1, 2, 1, -4};
	int target = 1;
	printf("Result: %d", sol.threeSumClosest(nums, target));
}