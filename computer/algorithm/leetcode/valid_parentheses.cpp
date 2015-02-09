#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
		stack<int> is;
		is.push(s[0]);
		for (int i= 1; i < s.length(); i++) {
			if (is.empty())
				is.push(s[i]);
			else if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				is.push(s[i]);
			else {
				int t = is.top();
				if ((t == '(' && s[i] == ')') || (t == '[' && s[i] == ']') || (t == '{' && s[i] == '}'))
					is.pop();
				else
					is.push(s[i]);
			}
		}		
		if (is.empty())
			return true;
		
		return false;
    }
};

int main() {
	//string t = "()[]{}";
	Solution s;
	cout << s.isValid("(])") << endl;
	return 0;
}
