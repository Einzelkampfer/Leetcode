#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int numTrees(int n) {
        vector<bool> dp(n, false);
        return cal(n, dp);
    }
    int cal(int n, vector<bool>& dp) {
        vector<int> nextPos;
        for (int i = 0; i < n; ++i) {
            if (!dp[i]) {
                int j = i;
                while (j < n && !dp[j])
                    ++j;
                if (j != i + 1) {
                    for (int k = i; k < j; ++k)
                        nextPos.push_back(k);
                    i = j;
                }
            }
        }
        if (nextPos.empty()) {
            return 1;
        }
        int l = nextPos.size();
        int result = 0;
        for (int k = 0; k < l; ++k) {
            dp[nextPos[k]] = true;
            result += cal(n, dp);
            dp[nextPos[k]] = false;
        }
        return result;
    }
};
int main() {
    Solution s;
    printf("%d\n", s.numTrees(4));
    return 0;
}
