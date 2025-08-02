/* #17 [Medium]
https://leetcode.com/problems/letter-combinations-of-a-phone-number/

##ReDo

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:
	Input: digits = "23"
	Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
	Input: digits = ""
	Output: []

Example 3:
	Input: digits = "2"
	Output: ["a","b","c"]

Runtime--> 0ms, Beats:100%
Memory--> 9.21MB, Beats:58.09%
Score--> 79.045%
*/

#include <iostream>
#include <vector>

class Solution {
public:
	void generate(int index, std::vector<std::string>& temp, std::string s, std::vector<std::string>& ans ){
		if(index==temp.size()){
			ans.push_back(s);
			return;
		}

		for(int j=0;j<temp[index].size();j++){
			char c= temp[index][j];
			generate(index+1, temp, s+c, ans);
		}
	}

	std::vector<std::string> letterCombinations(std::string digits) {
		std::vector<std::string> ans;
		if(digits.size()==0) return ans;
		std::vector<std::string> temp;
		for(int i=0;i<digits.size();i++){
			if(digits[i]=='2'){
				temp.push_back("abc");
			}
			else if(digits[i]=='3'){
				temp.push_back("def");
			}
			else if(digits[i]=='4'){
				temp.push_back("ghi");
			}
			else if(digits[i]=='5'){
				temp.push_back("jkl");
			}
			else if(digits[i]=='6'){
				temp.push_back("mno");
			}
			else if(digits[i]=='7'){
				temp.push_back("pqrs");
			}
			else if(digits[i]=='8'){
				temp.push_back("tuv");
			}
			else if(digits[i]=='9'){
				temp.push_back("wxyz");
			}
		}
		generate(0, temp, "", ans);
		return ans;
	}
};

int main() {
	Solution sol;
	std::string str = "735";
	std::vector<std::string> res = sol.letterCombinations(str);
	for (int i=0; i<res.size(); i++) {
		printf("Result: %s\n", res[i].c_str());
	}
}