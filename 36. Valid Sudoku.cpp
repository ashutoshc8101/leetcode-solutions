class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<int, unordered_set<char>> row_mp;
        unordered_map<int, unordered_set<char>> column_mp;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                if (board[i][j] != '.') {
                    if (row_mp[i].find(board[i][j]) != row_mp[i].end()) {
                        return false;
                    }

                    row_mp[i].insert(board[i][j]);

                    if (column_mp[j].find(board[i][j]) != column_mp[j].end()) {
                        return false;
                    }
                    column_mp[j].insert(board[i][j]);
                }
            }
        }

        unordered_set<char> st;

        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    for (int m = 0; m < 3; m++) {
                        if (board[3 * i + k][3 * j + m] != '.') {
                            if (st.find(board[3 * i + k][3 * j + m]) != st.end()) {
                                return false;
                            }
                            st.insert(board[3 * i + k][3 * j + m]);
                        }
                    }
                }
                unordered_set<char> empty;
                st = empty;
            }
        }

        return true;
    }
};