#include <cstdio>
#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
	Solution() {
		numtable['I'] = 1;
		numtable['V'] = 5;
		numtable['X'] = 10;
		numtable['L'] = 50;
		numtable['C'] = 100;
		numtable['D'] = 500;
		numtable['M'] = 1000;
	}
    int romanToInt(string s) {
        int l = s.size();
        int count = 0;
        int lastdigit = numtable[s[l - 1]];
        for (int i = l - 1; i >= 0; --i) {
        	int t1 = numtable[s[i]];
        	if (t1 < lastdigit) {
        		count -= t1;
        	} else {
        		lastdigit = t1;
        		count += t1;
        	}
        }
        return count;
        return 0;
    }
private:
	map<char, int> numtable;
};
int main() {
	Solution s;
	cout << s.romanToInt("CXCIX");
	return 0;
}

