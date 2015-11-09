#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
    	int l = s.size();
    	string result = "";
        for (int i = 0; i < numRows + 1; ++i) {
        	for (int k = i; k < l; k += numRows + 1) {
        		result += s[k];
        	}
        }
        return result;
    }
};
int main() {
	Solution s;
	cout << s.convert("PAYPALISHIRING", 3);
	return 0;
}
