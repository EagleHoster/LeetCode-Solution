/* #4 [Hard]
https://leetcode.com/problems/median-of-two-sorted-arrays/

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
	Input: nums1 = [1,3], nums2 = [2]
	Output: 2.00000
	Explanation: merged array = [1,2,3] and median is 2.

Example 2:
	Input: nums1 = [1,2], nums2 = [3,4]
	Output: 2.50000
	Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.


Runtime--> ms, Beats:%
Memory--> MB, Beats:%
Score--> %
*/

#include <iostream>
#include <vector>

class Solution {
	public:
		double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
			std::vector<int> sorted;
			int i = 0, j = 0;
			int num1s = nums1.size();
			int num2s = nums2.size();
			while (i < num1s && j < num2s) {
				if (nums1[i] < nums2[j]) sorted.push_back(nums1[i++]);
				else sorted.push_back(nums2[j++]);
			}
			while (i < num1s) sorted.push_back(nums1[i++]);
			while (j < num2s) sorted.push_back(nums2[j++]);
			
			int total = (num1s + num2s);
			
			if (total % 2) {
				return sorted[total/2];
			} else {
				return (sorted[(total/2)-1] + sorted[total/2])/2.0;
			}
		}
};

int main() {
	Solution sol;
	std::vector nums1 = {1,2};
	std::vector nums2 = {3,4};
	
	printf("Result: %f", sol.findMedianSortedArrays(nums1, nums2));
}