class Solution {
public:
    int lcs(string &text1, string &text2, int n, int m, vector<vector<int>> &dp) {
        if (n == 0 || m == 0) {
            return 0;
        }

        if (dp[n][m] != -1) {
            return dp[n][m];
        }

        if (text1[n - 1] == text2[m - 1]) {
            return dp[n][m] = 1 + lcs(text1, text2, n - 1, m - 1, dp);
        }

        return dp[n][m] = max(lcs(text1, text2, n, m - 1, dp), lcs(text1, text2, n - 1, m, dp));
    }

    int minInsertions(string s) {
     string rs(s);

     reverse(rs.begin(), rs.end());

     vector<vector<int>> dp(s.length() + 1, vector<int>(s.length() + 1, -1));

     return s.size() - lcs(s, rs, s.size(), rs.size(), dp);
    }
};