#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) {
    	int al = a.size();
    	int bl = b.size();
    	int l = (al > bl ? al : bl);
    	int carry = 0;
    	string result = "";
        for (int i = 0; i < l; ++i) {
        	int posa = al - i - 1;
        	int posb = bl - i - 1;
        	char c;
        	int sum = 0;
        	if (posa < 0 || posb < 0) {
				if (posa < 0) {
					sum = (b[posb] - '0') + carry;
				}
				else {
					sum = (a[posa] - '0') + carry;
				}
        	} else {
        		sum = (a[posa] + b[posb] - '0' - '0') + carry;
        	}
        	c = sum % 2 + '0';
			carry = sum / 2;
        	result = c + result;
        }
        if (carry != 0)
        	result = "1" + result;
        return result;
    }
};
int main() {
	Solution s;
	cout << s.addBinary("1010", "10111") << endl;
	return 0;
}
