#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        for (int i = 0; i <= n; ++i) {
        	result ^= i;
		}
		for (int i = 0; i < n; ++i) {
			result ^= nums[i];

		}
		return result; 
    }
};
int main() {
	Solution s;
	int a[1] = {1};
	vector<int> nums(a, a + 1);
	printf("%d", s.missingNumber(nums));
	return 0;
}
