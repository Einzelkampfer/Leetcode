#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        return nums[n / 2];
    }
};
int main() {
    Solution s;
    int a[10] = {2, 2, 2, 3, 4};
    vector<int> v(a, a + 5);
    printf("%d\n", s.majorityElement(v));
    return 0;
}
