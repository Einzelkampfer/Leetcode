#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
	bool recurseSearch(int n, vector<vector<int> >& matrix, int target, int begin, int end) {
    	if (begin > end)
    		return false;
    	int l = (end + begin) / 2;
    	if (matrix[l / n][l % n] == target)
    		return true;
    	else if (matrix[l / n][l % n] < target)
    		return recurseSearch(n, matrix, target, l + 1, end);
    	else
    		return recurseSearch(n, matrix, target, begin, l - 1);
    }
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
    	int m = matrix.size();
    	int n = matrix[0].size();
    	int s = m * n;
        return recurseSearch(n, matrix, target, 0, s - 1);
    }
    
};
int main() {
	Solution s;
	int mat[10][10] = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50}};
	vector<vector<int> > matrix;
	for (int i = 0; i < 3; ++i) {
		vector<int> row;
		matrix.push_back(row);
		for (int j = 0; j < 4; ++j) {
			matrix[i].push_back(mat[i][j]);
		}
	}
	if (s.searchMatrix(matrix, 4)) {
		printf("hi\n");
	} 
	return 0;
}
