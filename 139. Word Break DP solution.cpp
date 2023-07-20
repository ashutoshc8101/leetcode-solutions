class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        // dp solution

        vector<bool> dp(s.length() + 1, false);
        unordered_map<string, int> ump;

        for (string word: wordDict) ump[word]++;

        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || dp[i]) {
                for (string word: wordDict) {
                    if (ump.find(s.substr(i, word.length())) != ump.end()) {
                        dp[i + word.length()] = true;

                        if (i + word.length() == s.length()) return true;
                    }
                }
            }
        }

        return false;
    }
};