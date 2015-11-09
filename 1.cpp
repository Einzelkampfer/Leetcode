#include <vector>
#include <cstdio>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l = nums.size();
        map<int, int> hashing;
		for (int i = 0; i < l; ++i) {
			hashing[nums[i]] = i + 1;
		}
		for (int i = 0; i < l; ++i) {
			int dif = target - nums[i];
			map<int, int>::iterator it;
			it = hashing.find(dif);
			if (it != hashing.end()) {
				int j = it -> second;
				if (i + 1 != j) {
					vector<int> result;
					if (i + 1 > j) {
						result.push_back(j);
						result.push_back(i + 1);
					} else {
						result.push_back(i + 1);
						result.push_back(j);
					}
					return result;
				}
			}
		}
    }
};

int main() {
	Solution s;
	int a[5] = {2, 7, 11, 15};
	vector<int> nums(a, a + 4);
	vector<int> solu = s.twoSum(nums, 9);
	printf("%d %d", solu[0], solu[1]);
	return 0;
}
