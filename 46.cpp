#include <cstdio>
#include <vector>
using namespace std;
void recurSelect(vector<vector<int> >& permutations, vector<int>& nums, vector<bool>& select, vector<int> temp) {
	if (temp.size() == nums.size()) {
		permutations.push_back(temp);
	}
	int l = select.size();
	for (int i = 0; i < l; ++i) {
		
		if (!select[i]) {
			select[i] = true;
			temp.push_back(nums[i]);
			recurSelect(permutations, nums, select, temp);
			temp.pop_back();
			select[i] = false;
		}
	}
}
class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        int l = nums.size();
        vector<bool> select;
        for (int i = 0; i < l; ++i)
        	select.push_back(false);
        vector<vector<int> > permutations;
        vector<int> temp;
        recurSelect(permutations, nums, select, temp);
        return permutations;
    }
};
int main() {
	Solution s;
	vector<int> nums;
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(3);
	vector<vector<int> > permutation = s.permute(nums);
	for (int i = 0; i < permutation.size(); ++i) {
		for (int j = 0; j < permutation[i].size(); ++j) {
			printf("%d ", permutation[i][j]);
		}
		printf("\n");
	}
	printf("%d", permutation.size());
	return 0;
}

