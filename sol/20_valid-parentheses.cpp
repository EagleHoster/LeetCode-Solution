/* #20 [Easy]
https://leetcode.com/problems/valid-parentheses/

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:
1.Open brackets must be closed by the same type of brackets.
2.Open brackets must be closed in the correct order.
3.Every close bracket has a corresponding open bracket of the same type.
 

Example 1:
	Input: s = "()"
	Output: true

Example 2:
	Input: s = "()[]{}"
	Output: true

Example 3:
	Input: s = "(]"
	Output: false

Example 4:
	Input: s = "([])"
	Output: true

Example 5:
	Input: s = "([)]"
	Output: false

Runtime--> 0ms, Beats:100%
Memory--> 8.50MB, Beats:99.24%
Score--> 99.62%
*/

#include <iostream>

class Solution {
public:
    bool isValid(std::string s) {
        std::string check = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                check.push_back(s[i]);
            } else {
                if (check.size() < 1) return false;
                char last = check.back();
                
                switch(s[i]) {
                    case ')':
                        if (last == '(') {
                            check.pop_back();
                            break;
                        }
                        return false;
                    case ']':
                        if (last == '[') {
                            check.pop_back();
                            break;
                        }
                        return false;
                    case '}':
                        if (last == '{') {
                            check.pop_back();
                            break;
                        }
                        return false;
                    default:
                        return false;
                }
            }
        }
        return check.empty();
    }
};

int main() {
	Solution sol;
	std::string s = "{()[]{}}}";
	printf("Result: %d", sol.isValid(s));
}