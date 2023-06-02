class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, int i, vector<bool> &visited) {
        visited[i] = true;

        for (int j = 0; j < isConnected.size(); j++) {
            if (isConnected[i][j] && !visited[j]) {
                dfs(isConnected, j, visited);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int result = 0;

        vector<bool> visited(isConnected.size(), false);

        for (int i = 0; i < isConnected.size(); i++) {
            if (!visited[i]) {
                result++;
                dfs(isConnected, i, visited);
            }
        }

        return result;
    }
};