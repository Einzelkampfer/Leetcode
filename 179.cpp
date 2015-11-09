#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#define MAX 15
using std::string;
using std::vector;
using std::cout;
using std::endl;

bool cmp(const string& s1, const string& s2) {
	return (s1 + s2) > (s2 + s1);
}
class Solution {
public:
    string largestNumber(vector<int> &num) {
    	vector<string> numbers;
    	vector<int>::iterator it;
    	for (it = num.begin(); it != num.end(); ++it) {
    		string numStr = numberToStr(*it);
    		numbers.push_back(numStr);
    	}
    	sort(numbers.begin(), numbers.end(), cmp);
    	string res = "";
    	vector<string>::iterator it2;
    	bool firstZero = (*numbers.begin() == "0");
    	for (it2 = numbers.begin(); it2 != numbers.end(); ++it2) {
    		if (firstZero && (*it2 == "0") && it2 + 1 != numbers.end())
    			continue;
    		firstZero = false;
    		res += *it2;
    	}
    	return res;
    }
    string numberToStr(int num) {
    	char bits[MAX];
    	int n = 0;
    	if (num == 0) {
    		n = 1;
    		bits[0] = '0';
    		bits[1] = '\0';
    	} else {
    		while (num != 0) {
    			bits[n++] = (num % 10) + '0';
    			num /= 10;
    		}
    		bits[n] = '\0';
    	}
    	for (int i = 0, j = n - 1; i < j; ++i, --j) {
    		char temp = bits[i];
    		bits[i] = bits[j];
    		bits[j] = temp;
    	}
    	return string(bits);
    }
};

int main() {
	Solution s;
	vector<int> v;
	int a[] = {1, 0, 0, 0};
	for (int i = 0; i < 4; ++i) {
		v.push_back(a[i]);
	}
	printf("%s", s.largestNumber(v).c_str());
	return 0;
}
