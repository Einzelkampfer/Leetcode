#include <cstdio>
bool situation[200000];

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
    	int begin = 1, end = n;
    	while (1) {
    		int pos = begin + (end - begin) / 2;\;
	    	if (!isBadVersion(pos)) {
	    		begin = pos + 1;
	    	} else {
	    		if (pos == 1 || !isBadVersion(pos - 1)) {
	    			return pos;
	    		} else {
	    			end = pos - 1;
	    		}
	    	}
    	}
    }
};

bool isBadVersion(int version) {
	return situation[version - 1];
}

int main() {
	for (int i = 0; i < 200000; ++i) {
		if (i < 10000)
			situation[i] = false;
		else
			situation[i] = true;
	}
	Solution s;
	printf("%d\n", s.firstBadVersion(200000));
	return 0;
}
