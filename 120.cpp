#include <cstdio>
#include <vector>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int> >& triangle) {
		int m = triangle.size();
		vector<int> solutions;
		for (int i = 0; i < m; ++i) {
			solutions.push_back(triangle[m - 1][i]);
		}
		for (int i = m - 2; i >= 0; --i) {
			for (int j = 0; j < i + 1; ++j) {
				solutions[j] = triangle[i][j] + (solutions[j] < solutions[j + 1] ? solutions[j] : solutions[j + 1]);
			} 
		}
		return solutions[0];
    }
};
int main() {
	vector<int> rows[4];
	rows[0].push_back(2);
	rows[1].push_back(3);
	rows[1].push_back(4);
	rows[2].push_back(6);
	rows[2].push_back(5);
	rows[2].push_back(7);
	rows[3].push_back(4);
	rows[3].push_back(1);
	rows[3].push_back(8);
	rows[3].push_back(3);
	vector<vector<int> > triangle;
	for (int i = 0; i < 4; ++i) {
		triangle.push_back(rows[i]);
	}
	Solution s;
	printf("%d\n", s.minimumTotal(triangle));
	return 0;
}
