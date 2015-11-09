#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int minPathSum(vector<vector<int> >& grid) {
        vector<vector<int> > solution;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; ++i) {
        	vector<int> row;
			solution.push_back(row);
			for (int j = 0; j < n; ++j) {
				solution[i].push_back(grid[i][j]);
			}
        }
        for (int i = m - 1; i >= 0; --i) {
        	for (int j = n - 1; j >= 0; --j) {
        		if (i == m - 1 && j == n - 1) {
        			continue;
        		} else if (i == m - 1 && j != n - 1) {
        			solution[i][j] = solution[i][j] + solution[i][j + 1];
        		} else if (i != m - 1 && j == n - 1) {
        			solution[i][j] = solution[i][j] + solution[i + 1][j];
        		} else {
        			solution[i][j] = solution[i][j] + (solution[i + 1][j] < solution[i][j + 1] ? solution[i + 1][j] : solution[i][j + 1]);
        		}
        	}
        }
        return solution[0][0];
    }
};
int main() {
	Solution s;
	int mat[10][10] = {{1, 2, 3, 5}, {2, 3, 2, 4}, {2, 4, 5, 6}, {3, 5, 3, 2}};
	int m = 4;
	int n = 4;
	vector<vector<int> > grid;
	for (int i = 0; i < m; ++i) {
		vector<int> row;
		grid.push_back(row);
		for (int j = 0; j < n; ++j) {
			grid[i].push_back(mat[i][j]);
		}
	}
	s.minPathSum(grid);
	return 0;
}


