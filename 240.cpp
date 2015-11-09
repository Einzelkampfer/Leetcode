#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    bool searchRow(vector<int>& row, int target) {
        int n = row.size();
        int a = 0, b = n - 1;
        while (a < b) {
            int mid = (a + b) / 2;
            if (row[mid] < target)
                a = mid + 1;
            else
                b = mid;
        }
        return row[a] == target;
    }
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int row = matrix.size();
        if (row == 0)
            return false;
        int col = matrix[0].size();
        for (int i = 0; i < row; ++i) {
            //printf("%d %d %d\n", matrix[i][0], matrix[i][col - 1], target);
            if (matrix[i][0] <= target && matrix[i][col - 1] >= target) {
                //printf("row%d\n", i);
                if (searchRow(matrix[i], target))
                    return true;
            }
        }
        return false;
    }
};
int main() {
    int a[5][5] = {
  {1,   4,  7, 11, 15},
  {2,   5,  8, 12, 19},
  {3,   6,  9, 16, 22},
  {10, 13, 14, 17, 24},
  {18, 21, 23, 26, 30}
};
    vector<vector<int> > matrix;
    for (int i = 0; i < 4; ++i) {
        vector<int> temp(a[i], a[i] + 4);
        matrix.push_back(temp);
    }
    Solution s;
    if (s.searchMatrix(matrix, 15))
        printf("fuck\n");
    return 0;
}
