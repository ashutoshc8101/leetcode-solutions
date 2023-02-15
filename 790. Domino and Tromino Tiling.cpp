class Solution {
public:
    long long numTilings(int n) {
        if (n == 0) {
            return 0;
        }

        if (n < 3) {
            return n;
        }

        vector<long long> dp(n + 1, 0);

        int M = 1000000007;

        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        if (n < 4) {
            return dp[n];
        }

        for (int i = 4; i <= n; i++) {
            dp[i] = 2 * dp[i - 1] + dp[i - 3];
            dp[i] %= M;
        }

        return dp[n];
    }
};