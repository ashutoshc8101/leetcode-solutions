class Solution {
public:
    vector<string> solveRec(string s, int i, unordered_map<string, int> &ump,
    vector<vector<string>> &dp) {
        if (i > s.length()) {
            return vector<string>();
        }

        if (dp[i].size() > 0) return dp[i];

        vector<string> results;

        for (int j = i; j < s.length(); j++) {
            string substr = s.substr(i, j - i + 1);

            if (ump.find(substr) != ump.end()) {
                if (j + 1 == s.length()) {
                    results.push_back(substr);
                } else {
                    vector<string> rs = solveRec(s, j + 1, ump, dp);

                    for (string r: rs) {
                        results.push_back(substr + " " + r);
                    }
                }
            }
        }

        return dp[i] = results;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string> results;
        unordered_map<string, int> ump;
        vector<vector<string>> dp(s.length(), vector<string>());

        for (string word: wordDict) ump[word]++;

        return solveRec(s, 0, ump, dp);
    }
};