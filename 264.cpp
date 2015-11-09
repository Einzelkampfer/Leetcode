#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int nthUglyNumber(int n) {
        if (n == 1)
            return 1;
        int base[4] = {2, 3, 4, 5};
        int result[4] = {2, 3, 4, 5};
        vector<int> v(result, result + 4);
        int i = 0;
        while (v.size() < n - 1) {
            for (int j = 0; j < 4; ++j)
                v.push_back(v[i] * base[j]);
            ++i;
        }
        return v[n - 2];
    }
};
int main() {
    Solution s;
    for (int i = 1; i < 100; ++i) {
        printf("%d\n", s.nthUglyNumber(i));
    }
    return 0;
}
