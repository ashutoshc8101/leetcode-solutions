class Solution {
public:
    int solveRec(int k, int n, vector<vector<int>> &dp) {
        if (n == 0 || n == 1) return n;

        if (k == 1) return n;

        if (dp[k][n] != -1) return dp[k][n];

        int minVal = INT_MAX;

        int left = 0, right = n;
        int temp = 0;

        while (left <= right) {
            int mid = (left + right) / 2;

            int down = solveRec(k - 1, mid - 1, dp);
            int up = solveRec(k, n - mid, dp);

            temp = 1 + max(down, up);

            if (down < up) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }

            minVal = min(minVal, temp);
        }

        return dp[k][n] = minVal;
    }

    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));

        return solveRec(k, n, dp);
    }
};