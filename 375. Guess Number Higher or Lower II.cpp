class Solution {
public:
    int solveRec(int low, int high, vector<vector<int>> &dp) {
        if (low >= high) {
            return 0;
        }

        if (dp[low][high] != -1) return dp[low][high];

        int minCost = INT_MAX;

        for (int k = low; k <= high; k++) {
            minCost = min(minCost, k + max(solveRec(low, k - 1, dp), solveRec(k + 1, high, dp)));
        }

        return dp[low][high] = minCost;
    }

    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));

        return solveRec(1, n, dp);
    }
};