#include <cstdio>
class Solution {
public:
    int singleNumber(int A[], int n) {
    	int temp = 0;
        for (int i = 0; i < n; ++i) {
        	temp ^= A[i];
        }
        return temp;
    }
};
int main() {
	Solution s;
	int A[] = {2, 2, 0, 0, 1, 1, 6}; 
	printf("%d", s.singleNumber(A, 7));
}
