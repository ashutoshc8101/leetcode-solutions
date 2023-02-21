class Solution {
public:
    int solveRec(vector<int> &values, int i, int j, vector<vector<int>> &dp) {
        if (i == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int result = INT_MAX;

        for (int k = i + 1; k < j; k++) {
            result = min(result, solveRec(values, i, k, dp) + values[i] * values[k] * values[j] +
            solveRec(values, k, j, dp));
        }

        return dp[i][j] = result == INT_MAX ? 0 : result;
    }

    int minScoreTriangulation(vector<int>& values) {
        vector<vector<int>> dp(values.size() + 1, vector<int>(values.size() + 1, -1));
        return solveRec(values, 0, values.size() - 1, dp);
    }
};