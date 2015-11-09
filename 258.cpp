#include <cstdio>
class Solution {
public:
    int addDigits(int num) {
    	if (num == 0)
    		return 0;
        int mod = num % 9;
        if (mod == 0)
        	mod = 9;
        return mod;
    }
};
int main() {
	Solution s;
	for (int i = 0; i < 25; ++i) {
		printf("%d %d\n", i, s.addDigits(i));
	}
	return 0;
}
