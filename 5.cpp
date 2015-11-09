#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
    	int l = s.size();
    	string result = s;
    	int pos = 0;
    	if (numRows == 1)
    		return s;
        for (int i = 0; i < numRows; ++i) {
        	if (i == 0 || i == numRows - 1) {
        		for (int k = i; k < l; k += (2 * numRows - 2)) {
        			result[pos++] = s[k];
        		}
        	} else {
        		int turn = 0;
        		int k = i;
        		while (k < l) {
        			result[pos++] = s[k];
        			if (turn % 2 == 0)
        				k += 2 * numRows - 2 * (i + 1);
        			else
        				k += 2 * i;
        			++turn;
        		}
        	}
        }
        return result;
    }
};
int main() {
	Solution s;
	cout << s.convert("A", 3);
	return 0;
}

