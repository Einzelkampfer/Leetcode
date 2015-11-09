#include <cstdio>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char> >& board) {
        bool record[9];
        for (int i = 0; i < 9; ++i) {
            printf("row %d\n", i);
            memset(record, 0, sizeof(record));
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.')
                    if (!record[board[i][j] - '1'])
                        record[board[i][j] - '1'] = true;
                    else
                        return false;
            }
        }
        for (int i = 0; i < 9; ++i) {
            printf("col %d\n", i);
            memset(record, 0, sizeof(record));
            for (int j = 0; j < 9; ++j) {
                if (board[j][i] != '.')
                    if (!record[board[j][i] - '1'])
                        record[board[j][i] - '1'] = true;
                    else {
                        printf("%c", board[j][i]);
                        return false;
                    }

            }
        }

        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                memset(record, 0, sizeof(record));
                for (int k = i; k < i + 3; ++k) {
                    for (int l = j; l < j + 3; ++l) {
                        if (board[k][l] != '.')
                            if (!record[board[k][l] - '1'])
                                record[board[k][l] - '1'] = true;
                            else
                                return false;
                    }
                }
            }
        }
        return true;
    }
};
int main() {
    char a[9][9] = {{'.', '8', '7', '6', '5', '4', '3', '2', '1'},
                    {'2', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'3', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'4', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'5', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'6', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'7', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'8', '.', '.', '.', '.', '.', '.', '.', '.'},
                    {'9', '.', '.', '.', '.', '.', '.', '.', '.'}};
    vector<vector<char> > board;
    for (int i = 0; i < 9; ++i) {
        vector<char> temp(a[i], a[i] + 9);
        board.push_back(temp);
    }
    Solution s;
    if (s.isValidSudoku(board))
        printf("fuck\n");
	return 0;
}
