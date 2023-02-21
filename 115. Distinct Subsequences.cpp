class Solution {
public:
    int solveRec(string &s, string &t, int i, int j, vector<vector<int>> &dp) {
        if (j == t.length()) return 1;

        if (i == s.length() || j == t.length()) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == t[j]) {
            return dp[i][j] = solveRec(s, t, i + 1, j + 1, dp) + solveRec(s, t, i + 1, j, dp);
        }

        return dp[i][j] = solveRec(s, t, i + 1, j, dp);
    }

    int numDistinct(string s, string t) {
        vector<vector<int>> dp(s.length() + 1, vector<int>(t.length() + 1, -1));

        return solveRec(s, t, 0, 0, dp);
    }
};