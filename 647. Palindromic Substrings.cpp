class Solution {
public:
    bool isPalindrome(string s, int l, int r, vector<vector<int>> &dp) {
        if (l >= r) return true;

        if (dp[l][r] != -1) return dp[l][r];

        return dp[l][r] = s[l] == s[r] && isPalindrome(s, l + 1, r - 1, dp);
    }

    int countSubstrings(string s) {
        vector<vector<int>> dp(s.length(), vector<int>(s.length(), -1));

        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            for (int j = i; j < s.length(); j++) {
                if (isPalindrome(s, i, j, dp)) {
                    count++;
                }
            }
        }

        return count;
    }
};