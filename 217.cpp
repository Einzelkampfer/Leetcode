#include <cstdio>
#include <vector>
#include <set>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) {
        	set<int>::iterator it = s.find(nums[i]);
        	if (it == s.end())
				s.insert(nums[i]);
			else
				return true;
        }
        return false;
    }
};
int main() {
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(5);
	Solution s;
	if (s.containsDuplicate(nums)) {
		printf("hey");
	}
	return 0;
}

