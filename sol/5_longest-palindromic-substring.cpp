/* #5 [Medium]
https://leetcode.com/problems/longest-palindromic-substring/

Given a string s, return the longest palindromic substring in s.

Example 1:
	Input: s = "babad"
	Output: "bab"
	Explanation: "aba" is also a valid answer.

Example 2:
	Input: s = "cbbd"
	Output: "bb"

Runtime--> 8ms, Beats:76.12%
Memory--> 9.42MB, Beats:68.50%
Score--> 72.31%
*/

#include <iostream>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int start =0, maxLen =0;
        int left=0, right=0;
        for (int pos=0; pos<s.size(); pos++) {
        	for (int i=0; i<2; i++) {
	        	left=pos, right=pos+i;
	        	while (left>=0 && right<s.size() && s[left] == s[right]) {
	        		if (right-left+1 > maxLen) {
	        			start = left;
	        			maxLen = right-left+1;
	        		}
	        		--left;
		        	++right;
	        	}
        	}
        }

        return s.substr(start, maxLen);
    }
};

int main() {
	Solution sol;
	std::string s = "abcb";
	printf("Result: %s", sol.longestPalindrome(s).c_str());
}