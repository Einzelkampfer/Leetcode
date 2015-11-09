#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int l = nums.size();
        int i = 0;
        vector<string> result;
        while (i < l) {
        	int j = i + 1;
        	while (j < l && nums[j] == nums[j - 1] + 1) {
        		++j;
        	}
        	stringstream ss;
        	if (j != i + 1)
        		ss << nums[i] << "->" << nums[j - 1];
        	else
        		ss << nums[i];
        	string s;
        	ss >> s;
        	result.push_back(s);
        	i = j;
        }
        return result;
    }
};
int main() {
	int a[10] = {0,1,2,3,4,5};
	vector<int> v(a, a + 6);
	Solution s;
	vector<string> result = s.summaryRanges(v);
	for (int i = 0; i < result.size(); ++i)
		cout << result[i] << "\n";
	return 0;
}
