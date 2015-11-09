#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> result(rowIndex + 1, 1);
        if (rowIndex <= 1)
            return result;
        for (int i = 1; i < rowIndex; ++i) {
            vector<int> temp(result.begin(), result.begin() + i + 1);
            for (int j = 1; j <= i; ++j) {
                result[j] = temp[j - 1] + temp[j];
            }
        }
        return result;
    }
};
int main() {
    Solution s;
    for (int k = 0; k < 10; ++k) {
        vector<int> result = s.getRow(k);
        for (int i = 0; i < result.size(); ++i) {
            printf("%d ", result[i]);
        }
        printf("\n");
    }
    return 0;
}
