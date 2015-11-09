#include <stack>
#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int l = s.size();
        bool legal = true;
        for (int i = 0; i < l; ++i) {
        	if (s[i] == '}') {
        		if (!st.empty() && st.top() == '{') {
        			st.pop();
        		} else {
        			legal = false;
        		}
        	} else if (s[i] == ']') {
        		if (!st.empty() && st.top() == '[') {
        			st.pop();
        		} else {
        			legal = false;
        		}
        	} else if (s[i] == ')') {
        		if (!st.empty() && st.top() == '(') {
        			st.pop();
        		} else {
        			legal = false;
        		}
        	} else {
        		st.push(s[i]);
        	}
        	if (!legal)
        		break;
        }
        return (legal && st.empty());
    }
};
int main() {
	Solution s;
	if (s.isValid("[")) {
		cout << "fuck\n";
	}
}
