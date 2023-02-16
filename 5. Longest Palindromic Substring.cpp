class Solution
{
public:
    bool isPalindrome(string &s, int i, int j, vector<vector<int>> &dp) {
        if (i >= j) {
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = (s[i] == s[j] && isPalindrome(s, i + 1, j - 1, dp));
    }

    string longestPalindrome(string s) {
        int max_i = 0;
        int max_j = 0;
        int length = 1;

        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));

        for (int i = 0; i < s.length(); i++) {
            for (int j = 0; j < s.length(); j++) {
                if (isPalindrome(s, i, j, dp)) {
                    if (j - i + 1 > length) {
                        max_i = i;
                        max_j = j;
                        length = j - i + 1;
                    }
                }
            }
        }

        string result = "";

        for (int i = max_i; i <= max_j; i++) {
            result += s[i];
        }

        return result;
    }
};