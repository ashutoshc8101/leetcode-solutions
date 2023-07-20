class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        // bfs solution

        vector<bool> visited(s.length(), false);
        unordered_map<string, int> ump;

        for (string word: wordDict) ump[word]++;

        queue<int> q;
        q.push(0);

        while (!q.empty()) {
            int idx = q.front();

            if (idx == s.length()) return true;
            q.pop();

            for (int i = idx; i < s.length(); i++) {
                string sbstr = s.substr(idx, i - idx + 1);

                if (ump.find(sbstr) != ump.end()) {
                    if (!visited[i]) {
                        q.push(i + 1);
                        visited[i] = true;
                    }
                }
            }
        }

        return false;
    }
};