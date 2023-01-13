class Solution {
public:
    vector<int> dfs(
        vector<vector<int>> &adjM, int u,
        int parent, string &labels, vector<int> &res
    ) {
        vector<int> result(26, 0);

        result[labels[u] - 'a']++;

        vector<int> response;

        for (int v : adjM[u]) {
            if (v != parent) {
                response = dfs(adjM, v, u, labels, res);
                for (int i = 0; i < 26; i++) {
                    result[i] += response[i];
                }
            }
        }

        res[u] = result[labels[u] - 'a'];

        return result;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adjM(n, vector<int>());

        for (vector<int> edge: edges) {
            adjM[edge[0]].push_back(edge[1]);
            adjM[edge[1]].push_back(edge[0]);
        }

        vector<int> response(n, 0);

        dfs(adjM, 0, -1, labels, response);

        return response;
    }
};