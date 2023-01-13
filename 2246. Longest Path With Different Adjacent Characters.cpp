class Solution {
public:
    int dfs(vector<vector<int>> &adjM, int u, int parent, string &s, int &result) {
        int greater = 0, smaller = 0;
        for (int v : adjM[u]) {
            if (v != parent) {
                int curr = dfs(adjM, v, u, s, result);
                if (s[v] == s[u]) continue;

                if (curr >= greater) {
                    smaller = greater;
                    greater = curr;
                } else if (curr >= smaller) {
                    smaller = curr;
                }
            }
        }

        result = max(result, 1 + greater + smaller);

        return greater + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        const int n = parent.size();
        vector<vector<int>> adjM(n, vector<int>());

        for (int i = 1; i < n; i++) {
            adjM[parent[i]].push_back(i);
            adjM[i].push_back(parent[i]);
        }

        int result = 0;

        dfs(adjM, 0, -1, s, result);

        return result;
    }
};