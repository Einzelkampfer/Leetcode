#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        int time = k % n;
        int moveTime = 0;
        int a = 0;
        int b = time;
        int temp1 = nums[a];
        while (moveTime != n) {
            for (int i = 0; i < nums.size(); ++i)
                printf("%d ", nums[i]);
            printf("\n");
            int temp2 = nums[b];
            nums[b] = temp1;
            int temppos = b;
            if (b > n - time - 1) {
                b = b - n + time;
            } else {
                b = b + time;
            }
            a = temppos;
            temp1 = temp2;
            moveTime++;
        }

    }
};
int main() {
    int a[10] = {1,2,3,4,5,6,7};
    vector<int> v(a, a + 6);
    Solution s;
    s.rotate(v, 2);
    for (int i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");
    return 0;
}
