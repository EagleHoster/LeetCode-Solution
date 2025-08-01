/* #13 [Easy]
https://leetcode.com/problems/longest-common-prefix/

Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

Runtime--> 0ms, Beats:100%
Memory--> 11.92MB, Beats:49.01%
Score--> 74.505%
*/

#include <iostream>
#include <vector>

class Solution {
	public:
		std::string longestCommonPrefix(std::vector<std::string>& strs) {
			std::string result = strs[0];
			for (int i=1; i<strs.size(); i++) {
				while (strs[i].find(result) != 0) {
					result = result.substr(0, result.size()-1);
					if (result == "") return "";
				}
			}
			return result;
		}
};

int main() {
	Solution sol;
	std::vector<std::string> strs = {"flower","flow","f"};
	printf("Result: %s", sol.longestCommonPrefix(strs).c_str());
}