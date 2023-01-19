class Solution {
public:
    bool isPalindrome(string &s, int l, int r) {
        if (l >= r) return true;

        if (s[l] != s[r]) return false;

        return isPalindrome(s, l + 1, r - 1);
    }

    void solve(string &s, int l, int r, vector<vector<string>> &results, vector<string> &result) {
        if (l > r) {
            results.push_back(result);
        }

        for (int i = l; i <= r; i++) {
            if (isPalindrome(s, l, i)) {
                string str = "";

                for (int j = l; j <= i; j++) {
                    str += s[j];
                }

                result.push_back(str);
                solve(s, i + 1, r, results, result);
                result.pop_back();
            }
        }
    }


    vector<vector<string>> partition(string s) {
        vector<vector<string>> results;
        vector<string> result;

        solve(s, 0, s.length() - 1, results, result);

        return results;
    }
};