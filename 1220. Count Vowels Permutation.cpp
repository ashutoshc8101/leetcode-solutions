class Solution {
public:
    long long M = 1000000007;
    long long count(int n, int last, vector<vector<long long>> &dp) {
        if (n == 0) return 1;

        if (dp[n][last] != -1) return dp[n][last];

        if (last == 0) {
            return dp[n][last] = count(n - 1, 1, dp) % M;
        }

        if (last == 1) {
            return dp[n][last] = (count(n - 1, 0, dp) + count(n - 1, 2, dp)) % M;
        }

        if (last == 2) {
            return dp[n][last] = (count(n - 1, 0, dp) + count(n - 1, 1, dp) + count(n - 1, 3, dp) + count(n - 1, 4, dp)) % M;
        }

        if (last == 3) {
            return dp[n][last] = (count(n - 1, 2, dp) + count(n - 1, 4, dp)) % M;
        }

        if (last == 4) {
            return dp[n][last] = count(n - 1, 0, dp) % M;
        }

        return 0;
    }

    long long countVowelPermutation(int n) {
        long long ans = 0;

        vector<vector<long long>> dp(n, vector<long long>(5, -1));

        ans += count(n - 1, 0, dp);
        ans += count(n - 1, 1, dp);
        ans += count(n - 1, 2, dp);
        ans += count(n - 1, 3, dp);
        ans += count (n - 1, 4, dp);

        return ans % M;
    }
};