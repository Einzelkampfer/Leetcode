#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        recurCalculate(s, 0, result, 0, "", 0);
        return result;
    }
    
    void recurCalculate(string str, int position, vector<string>& results, int pointNum, string curStr, int curSegNum) {
		cout << curStr << "\t" << curSegNum << "\t" << pointNum << "\n";
    	if (position == str.size()) {
    		if (pointNum == 3) {
	    		results.push_back(curStr);
	    		cout << "result: " << curStr << "\n";
			}
    		return;
		}
		if (pointNum > 3) {
			return;
		}
		curStr += str[position];
		curSegNum *= 10;
		curSegNum += str[position] - '0';
		if (curSegNum * 10 + str[position + 1] - '0' <= 255) {
			recurCalculate(str, position + 1, results, pointNum, curStr, curSegNum);
		}
		if (position != str.size() - 1) {
			curStr += '.';
			pointNum++;
			recurCalculate(str, position + 1, results, pointNum, curStr, 0);
		}
		
	}
};
int main() {
	Solution s;
	vector<string> res = s.restoreIpAddresses("255255255255");
	cout << res.size() << "\n";
	for (int i = 0; i < res.size(); ++i)
		cout << res[i] << "\n"; 
	return 0;
}
