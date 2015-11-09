#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        vector<int> indexes;
        int l = strs.size();
        if (l == 0)
        	return "";
        if (l == 1)
        	return strs[0];
        int index = 0;
        while (1) {
        	bool equal = true;
        	for (int i = 0; i < l - 1; ++i) {
        		if (index == strs[i].size() || index == strs[i + 1].size()) {
        			equal = false;
        			break;
        		}
        		if (strs[i][index] != strs[i + 1][index]) {
        			equal = false;
        			break;
        		}
        	}
        	if (!equal) {
        		break;
        	} else {
        		++index;
        	}
        }
        return strs[0].substr(0, index);
    }
};
int main() {
	vector<string> v;
	v.push_back("");
	Solution s;
	cout << s.longestCommonPrefix(v) << "\n";
	return 0;
}
