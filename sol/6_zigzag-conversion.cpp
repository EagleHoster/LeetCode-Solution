/* #6 [Medium]
https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number of rows:
string convert(string s, int numRows);
 

Example 1:
Input: s = "PAYPALISHIRING", numRows = 3
Output: "PAHNAPLSIIGYIR"

Example 2:
Input: s = "PAYPALISHIRING", numRows = 4
Output: "PINALSIGYAHRPI"
Explanation:
P     I    N
A   L S  I G
Y A   H R
P     I


Example 3:
Input: s = "A", numRows = 1
Output: "A"

Runtime--> 3ms, Beats:76.82%
Memory--> 13.94MB, Beats:67.02%
Score--> 71.92%
*/

#include <iostream>
#include <vector>

class Solution {
	public:
		std::string convert(std::string s, int numRows) {
			if (numRows ==0 || s.size() < 1) return "";
			if (numRows==1 || s.size() <= numRows) return s;
			std::vector<std::string> buff(numRows);
			int cycle = numRows*2 -2;
			std::string result = "";
			for (int i=0; i<s.size(); i++) {
				int pos = i % cycle;
				if (pos >= numRows) {
					buff[cycle-pos] += s[i];
				} else {
					buff[pos] += s[i];
				}
			}
			for (int i=0; i<buff.size(); i++) {
				result += buff[i];
			}
			return result;
		}
};

int main() {
	Solution sol;
	std::string test = "PAYPALISHIRING";
	int numrow = 3;
	printf("Result: %s", sol.convert(test, numrow).c_str());
}