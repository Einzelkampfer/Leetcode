#include <cstdio>
class Solution {
public:
    bool isUgly(int num) {
        while (num % 5 == 0)
            num /= 5;
        while (num % 3 == 0)
            num /= 3;
        while (num % 2 == 0)
            num /= 2;
        return num == 1;
    }
};
int main() {
    Solution s;
    if (s.isUgly(14))
        printf("fuck\n");
}
