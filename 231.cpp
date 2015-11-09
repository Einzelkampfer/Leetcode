#include <cstdio>
class Solution {
public:
    bool isPowerOfTwo(int n) {
    	if (n <= 0)
    		return false;
        while (n % 2 != 1) {
        	n >>= 1;
        }
        return n == 1;
    }
};
int main() {
	Solution s;
	
	for (int i = -100; i <= 100; ++i) {
		if (s.isPowerOfTwo(i))
			printf("%d is\n", i);
	}
	return 0;
}
