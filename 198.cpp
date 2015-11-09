#include <vector>
#include <cstdio>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        int l = nums.size();
        if (l == 0)
        	return 0;
        if (l == 1)
        	return nums[0];
        if (l == 2)
        	return (nums[0] > nums[1]) ? nums[0] : nums[1];
		int a[2];
		a[0] = nums[0];
		a[1] = (nums[0] > nums[1]) ? nums[0] : nums[1];
		for (int i = 2; i < l; ++i) {
			//printf("%d %d\n", a[0], a[1]);
			int det = (nums[i] + a[0] > a[1]) ? (nums[i] + a[0]) : a[1];
			a[0] = a[1];
			a[1] = det;
		}
		return a[1];
    }
};
int main() {
	int a[10] = {2,1,1,2,3,5,4,10};
	vector<int> v(a, a + 4);
	Solution s;
	printf("%d\n", s.rob(v));
	return 0;
}
