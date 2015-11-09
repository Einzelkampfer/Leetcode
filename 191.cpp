#include <cstdio>
typedef int uint32_t; 
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int size = sizeof(uint32_t) * 8;
        uint32_t one = 1;
        int sum = 0;
        for (int i = 0; i < size; ++i) {
        	sum += (n & 1);
        	n >>= 1;
        }
        return sum;
    }
};
int main() {
	Solution s;
	printf("%d\n", s.hammingWeight(16));	
}
