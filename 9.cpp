#include <cstdio>

class Solution {
public:
	int reverse(int x) {
	    int abs = (x >= 0) ? x : -x;
	    int bits[20];
	    int n = 0;
	    if (abs == 0) {
	    	n = 1;
	    	bits[0] = 0;
	    } else {
	    	while (abs != 0) {
	    		bits[n] = abs % 10;
	    		abs /= 10;
	    		++n;
	    	}
	    }
	    int sum = 0;
	    for (int i = n - 1; i >= 0; --i) {
	    	int base = 1;
	    	for (int j = 0; j < n - i - 1; ++j) {
	    		base *= 10;
	    	}
	    	int add = base * bits[i];
	    	int maxFac = (base < bits[i]) ? bits[i] : base;
	    	if (add != 0 && add < maxFac) {
	    		sum = 0;
	    		break;
	    	}
	    	sum += add;
	   	}
	    if (sum < 0) {
	    	sum = 0;
	    } else {
	    	sum = (x < 0) ? -sum : sum;	
	    }
	    return sum;
	}
    bool isPalindrome(int x) {
        if (x < 0)
        	return false;
        else {
        	return (x == reverse(x));
        }
    }
};
int main() {
	Solution s;
	for (int i = 100; i < 1000; ++i) {
		if (s.isPalindrome(i)) {
			printf("hey:%i\n");
		}
	}
	return 0;
}
