/* #7 [Medium]
https://leetcode.com/problems/reverse-integer/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
Assume the environment does not allow you to store 64-bit integers (signed or unsigned).


Example 1:
Input: x = 123
Output: 321

Example 2:
Input: x = -123
Output: -321

Example 3:
Input: x = 120
Output: 21

Runtime--> ms, Beats:%
Memory--> MB, Beats:%
Score--> %
*/

#include <iostream>

class Solution {
	public:
		int reverse(int x) {
			int result = 0;
			int digit= 0;
			while (x != 0) {
				digit = x%10;
				
				if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) return 0;
            	if (result < INT_MIN / 10 || (result == INT_MIN / 10 && digit < -8)) return 0;
				
				result = result * 10 + digit;
				x = x / 10;
			}
			return result;
		}
};

int main() {
	Solution sol;
	int num = -2147483412;
	printf("Result: %d", sol.reverse(num));
}