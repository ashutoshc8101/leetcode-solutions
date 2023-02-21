class Solution {
public:
    long long M = 1000000007;

    long long solveRec(int i, int arrLen, int steps, vector<vector<long long>> &dp) {
        if (i < 0 || i >= arrLen || i > steps) return 0;

        if (steps == 0 && i == 0) {
            return 1;
        }

        if (steps == 0) {
            return 0;
        }

        if (dp[i][steps] != -1) return dp[i][steps];

        return dp[i][steps] = (solveRec(i - 1, arrLen, steps - 1, dp)+ solveRec(i, arrLen, steps - 1, dp)+
            solveRec(i + 1, arrLen, steps - 1, dp)) % M;
    }

    long long numWays(int steps, int arrLen) {
        vector<vector<long long>> dp(steps/2 + 1, vector<long long>(steps + 1, -1));

        return solveRec(0, arrLen, steps, dp);
    }
};