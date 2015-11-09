#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> dp(n, 1);
        m--;
        while (m--) {
            for (int i = n - 2; i >= 0; --i) {
                dp[i] = dp[i] + dp[i + 1];
            }
        }
        return dp[0];
    }
};
int main() {
    Solution s;
    printf("%d\n", s.uniquePaths(3, 4));
    return 0;
}
