#include <cstdio>
#include <string>
using namespace std;
class Solution {
public:
    int titleToNumber(string s) {
        int res = 0;
        int len = s.size();
        int pow = 1;
        for (int i = len - 1; i >= 0; --i) {
        	int bit = s[i] - 'A' + 1;
        	res += bit * pow;
        	pow *= 26;
        }
        return res;
    }
};
int main() {
	Solution s;
	printf("%d", s.titleToNumber("AA"));
	return 0;
}
