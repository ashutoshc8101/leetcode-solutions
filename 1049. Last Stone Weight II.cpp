class Solution {
public:
    int solveRec(vector<int> &stones, int i, int sum, vector<vector<int>> &dp) {
        if (i == stones.size()) return 0;

        if (dp[i][sum] != -1) return dp[i][sum];

        if (stones[i] <= sum) {
            return dp[i][sum] = max(stones[i] + solveRec(stones, i + 1, sum - stones[i], dp),
                solveRec(stones, i + 1, sum, dp));
        }

        return dp[i][sum] = solveRec(stones, i + 1, sum, dp);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int SUM = 0;

        for (int stone : stones) {
            SUM += stone;
        }

        vector<vector<int>> dp(stones.size() + 1, vector<int>((SUM / 2) + 1, -1));

        return SUM - 2 * solveRec(stones, 0, SUM / 2, dp);
    }
};