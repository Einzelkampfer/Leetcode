#include <cstdio>
class Solution {
public:
    bool isPerfectSquare(int num) {
        int i = 1, j = num;
        while (i <= j) {
        	long long mid = (j + i) / 2;
        	if (mid * mid == num)
        		return true;
        	else if (mid * mid > num)
        		j = mid - 1;
        	else
        		i = mid + 1;
		}
		return false;
    }
};
int main() {
	Solution s;
	int n = 2147483647;
	if (s.isPerfectSquare(n)) {
		printf("%d is", n);
	} else {
		printf("%d not", n); 
	}
	return 0;
}
