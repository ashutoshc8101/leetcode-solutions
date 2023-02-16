class Solution {
public:
    int solveRec(string &text1, string &text2, int i, int j, vector<vector<int>> &dp) {

        if (i == text1.length()) {
            return text2.length() - j;
        }

        if (j == text2.length()) {
            return text1.length() - i;
        }

        if (dp[i][j] != -1) return dp[i][j];

        if (text1[i] == text2[j]) {
            return dp[i][j] = solveRec(text1, text2, i + 1, j + 1, dp);
        }

        int insert = solveRec(text1, text2, i, j + 1, dp);
        int remove = solveRec(text1, text2, i + 1, j, dp);
        int replace = solveRec(text1, text2, i + 1, j + 1, dp);

        return dp[i][j] = 1 + min(insert, min(remove, replace));
    }

    int minDistance(string text1, string text2) {
        vector<vector<int>> dp(text1.length() + 1, vector<int>(text2.length() + 1, -1));

        return solveRec(text1, text2, 0, 0, dp);
    }
};s