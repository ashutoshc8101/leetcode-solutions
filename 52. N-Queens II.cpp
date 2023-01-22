class Solution {
public:
    bool check(vector<string> &result, int i, int j) {
        // Row check
        for (int x = i; x >= 0; x--) {
            if (result[x][j] == 'Q') return false;
        }

        // Column Check
        for (int y = j; y >= 0; y--) {
            if (result[i][y] == 'Q') return false;
        }

        // Left diagonal
        for (int x = i, y = j; x >= 0 && y >= 0; x--, y--) {
            if (result[x][y] == 'Q') return false;
        }

        // Right diagonal
        for (int x = i, y = j; y >= 0 && x < result.size(); x++, y--) {
            if (result[x][y] == 'Q') return false;
        }

        return true;
    }

    void solveRec(int j, vector<string> &result, int &results) {
        if (j == result.size()) {
            results++;
            return;
        }

        for (int i = 0; i < result.size(); i++) {
            if (check(result, i, j)) {
                result[i][j] = 'Q';
                solveRec(j + 1, result, results);
                result[i][j] = '.';
            }
        }
    }

    int totalNQueens(int n) {
        int results = 0;
        string s = "";

        for (int i = 0; i < n; i++) {
            s += ".";
        }

        vector<string> result(n, s);
        solveRec(0, result, results);

        return results;
    }
};