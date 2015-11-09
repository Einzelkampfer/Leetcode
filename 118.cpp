#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result;
        if (numRows == 0)
            return result;
        vector<int> first(1, 1);
        result.push_back(first);
        for (int i = 1; i < numRows; ++i) {
            vector<int> temp(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                temp[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result.push_back(temp);
        }
        return result;
    }
};
int main() {
    Solution s;
    vector<vector<int> > result = s.generate(5);
    for (int i = 0; i < result.size(); ++i) {
        for (int j = 0; j < result[i].size(); ++j) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}
