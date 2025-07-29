/* #3 [Medium]
https://leetcode.com/problems/longest-substring-without-repeating-characters/

Given a string s, find the length of the longest substring without duplicate characters.

Example 1:
	Input: s = "abcabcbb"
	Output: 3
	Explanation: The answer is "abc", with the length of 3.

Example 2:
	Input: s = "bbbbb"
	Output: 1
	Explanation: The answer is "b", with the length of 1.

Example 3:
	Input: s = "pwwkew"
	Output: 3
	Explanation: The answer is "wke", with the length of 3.
	Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

Runtime--> 0ms, Beats:100%
Memory--> 10.34MB, Beats:97.54%
Score--> 98.77%
*/

#include <iostream>

inline int getChar(char ch) {
	return (ch >= 32 && ch <= 126) ? ch - 32 : -1;
}

class Solution {
	private:
		std::bitset<95> set;
		int longest = 0;
	public:
		int lengthOfLongestSubstring(std::string s) {
			int left = 0, right = 0;
			while (right < s.size()) {
				if (set[getChar(s[right])] == 0) {
					set[getChar(s[right])] = 1;
					longest = std::max(longest, right-left+1);
					right++;
				} else {
					set[getChar(s[left])] = 0;
					left++;
				}
			}
			return longest;
		}
};

int main() {
	std::string str = "dvdf";
	Solution sol;
	printf("Result: %d\n", sol.lengthOfLongestSubstring(str));
}