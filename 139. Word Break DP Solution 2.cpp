class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        // dp solution

        vector<bool> dp(s.length(), false);
        unordered_map<string, int> ump;

        for (string word: wordDict) ump[word]++;

        for (int i = 0; i < s.length(); i++) {

            for (int j = 0; j < wordDict.size(); j++) {
                if (i == 0 || dp[i]) {
                    if (ump.find(s.substr(i, wordDict[j].size())) != ump.end()) {
                        dp[i + wordDict[j].size()] = true;
                        if (i + wordDict[j].size() == s.length()) return true;
                    }
                }
            }
        }

        for (int i = 0; i < dp.size(); i++) {
            cout << i << " : " << dp[i] << endl;
        }

        return false;
    }
};