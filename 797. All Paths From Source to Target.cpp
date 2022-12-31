class Solution {
public:
    void dfs(vector<vector<int>> &graph, int u, vector<int> &path, vector<vector<int>> &results) {
        path.push_back(u);
        if (u == graph.size() - 1) {
            results.push_back(path);
            path.pop_back();
            return;
        }

        for (int v : graph[u]) {
            dfs(graph, v, path, results);
        }
        path.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> vt;
        vector<int> path;

        dfs(graph, 0, path, vt);

        return vt;
    }
};