#include <cstdio>
#include <set>
#include <vector>
using namespace std;
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int l = nums.size();
        set<int> s;
        for (int i = 0; i < k + 1 && i < l; ++i) {
        	set<int>::iterator it = s.find(nums[i]);
	        if (it != s.end()) {
	        	return true;
	        }
	        s.insert(nums[i]);
        }
        for (int i = k + 1; i < l; ++i) {
        	s.erase(nums[i - k - 1]);
        	set<int>::iterator it = s.find(nums[i]);
        	if (it != s.end()) {
	        	return true;
	        }
	        s.insert(nums[i]);
        }
        return false;
    }
};
int main() {
	int a[10] = {2, 5, 4, 5, 6, 7, 2};
	vector<int> v(a, a + 7);
	Solution s;
	if (s.containsNearbyDuplicate(v, 2)) {
		printf("fuck\n");
	}
	
	return 0;
}
