#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroNum = 0;
        int n = nums.size();
        for (int i = n - 1; i >= 0; --i) {
            if (nums[i] == 0) {
                zeroNum++;
                for (int j = i + 1; j <= n - zeroNum; ++j) {
                    nums[j - 1] = nums[j];
                }
            }

        }
        for (int i = n - zeroNum; i < n; ++i) {
            nums[i] = 0;
        }
    }
};
int main() {
    int a[10] = {0,2,0,0,4};
    vector<int> v(a, a + 5);
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
    Solution s;
    s.moveZeroes(v);
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
