class Solution {
public:
    bool isValid(vector<vector<char>> &board, int i, int j, char k) {
        int row = i - i % 3;
        int column = j - j % 3;

        for (int m = 0; m < 9; m++) {
            if (board[m][j] == k) return false;
            if (board[i][m] == k) return false;

            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    if (board[row + x][column + y] == k) return false;
                }
            }
        }

        return true;
    }

    bool solveRec(vector<vector<char>> &board, int i, int j) {
        if (i == 9) return true;

        if (j == 9) return solveRec(board, i + 1, 0);

        if (board[i][j] == '.') {
            for (char k = '1'; k <= '9'; k++) {
                if (isValid(board, i, j, k)) {
                    board[i][j] = k;

                    if (solveRec(board, i, j + 1)) {
                        return true;
                    }

                    board[i][j] = '.';
                }
            }

            return false;
        }

        return solveRec(board, i, j + 1);
    }

    void solveSudoku(vector<vector<char>>& board) {
        solveRec(board, 0, 0);
    }
};