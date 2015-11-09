#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int> >& matrix) {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; ++i) {
        	for (int j = 0; j < n / 2; ++j) {
        		int temp = matrix[i][j];
        		matrix[i][j] = matrix[n - j - 1][i];
        		matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
        		matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
        		matrix[j][n - i - 1] = temp;
        	}
        }
    }
};

int main() {
	int mat[10][10] = {{3, 4, 2}, {1, 3, 5}, {5, 3, 6}};
	vector<vector<int> > matrix;
	for (int i = 0; i < 3; ++i) {
		vector<int> row;
		matrix.push_back(row);
		for (int j = 0; j < 3; ++j) {
			matrix[i].push_back(mat[i][j]);
		}
	}
	Solution s;
	s.rotate(matrix);
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			printf("%d ", matrix[i][j]);
		}
		printf("\n");
	}
	return 0;
}
