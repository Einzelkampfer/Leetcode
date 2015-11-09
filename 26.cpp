#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if (nums.empty())
    		return 0;
        vector<int>::iterator it = nums.begin(), it2 = it + 1;
        for (; it2 != nums.end(); ++it, ++it2) {
        	if (*it == *it2) {
        		nums.erase(it);
        		it--;
        		it2--;
        	}
        }
        return nums.size();
    }
};
int main() {
	int a[10] = {1, 1, 2, 2, 3, 3, 3, 4};
	vector<int> v(a, a + 8);
	Solution s;
	for (int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	printf("\n");
	printf("%d\n", s.removeDuplicates(v));
	for (int i = 0; i < v.size(); ++i)
		printf("%d ", v[i]);
	printf("\n");
	return 0;
}
