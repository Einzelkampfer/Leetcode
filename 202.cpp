#include <set>
#include <cstdio>
using namespace std;
class Solution {
public:
    bool isHappy(int n) {
        int a = n;
        set<int> appear;
        while (1) {
            if (a == 1)
                return true;
            appear.insert(a);
            int squareSum = 0;
            while (a != 0) {
                int digit = a % 10;
                a /= 10;
                squareSum += (digit * digit);
            }
            set<int>::iterator it = appear.find(squareSum);
            if (it != appear.end()) {
                return false;
            } else {
                appear.insert(squareSum);
                a = squareSum;
            }
        }
    }
};
int main() {
    Solution s;
    for (int i = 0; i < 100; ++i) {
        if (s.isHappy(i))
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}
