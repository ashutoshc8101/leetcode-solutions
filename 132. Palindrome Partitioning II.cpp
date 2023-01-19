class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        if (l >= r) return true;

        if (s[l] != s[r]) return false;

        return isPalindrome(s, l + 1, r - 1);
    }

    int solve(string &s, int l, vector<int> &dp) {
        if (l == s.length()) {
            return 0;
        }

        if (dp[l] != -1) {
            return dp[l];
        }

        int result = INT_MAX - 1;

        for (int i = l; i < s.length(); i++) {
            if (isPalindrome(s, l, i)) {
                string str = "";

                for (int j = l; j <= i; j++) {
                    str += s[j];
                }

                result = min(result, 1 + solve(s, i + 1, dp));
            }
        }

        return dp[l] = result;
    }

    int minCut(string s) {
        vector<int> dp(s.length(), -1);

        return solve(s, 0, dp) - 1;
    }
};