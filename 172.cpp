#include <cstdio>
class Solution {
public:
    int trailingZeroes(int n) {
        if (n == 0)
            return 0;
        int fac = 1;
        int i = n;
        while (i != 1) {
            fac *= i;
            i--;
        }
        int zeroNum = 0;
        int divide = 10;
        while (fac % divide == 0) {
            divide *= 10;
            zeroNum++;
        }
        //printf("%d %d\n", fac, zeroNum);
        return zeroNum;
    }
};
int main() {
    Solution s;
    for (int i = 1; i < 10; ++i) {
        printf("%d\n", s.trailingZeroes(i));
    }
    return 0;
}
