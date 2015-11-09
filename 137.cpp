#include <cstdio>
class Solution {
public:
    int singleNumber(int A[], int n) {
        for (int i = 1; i < n; ++i) {
        	A[0] ^= A[i];
        }
        return A[0];
    }
};
int main() {
	Solution s;
	int A[] = {2, 2, 2, 3, 3, 3, 4};
	printf("%d", s.singleNumber(A, 7));
	return 0;
}
