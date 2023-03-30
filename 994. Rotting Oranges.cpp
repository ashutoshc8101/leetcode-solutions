class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &res, int dist) {
        if (i == grid.size() || j == grid[0].size() || i < 0 || j < 0) {
            return;
        }

        if (grid[i][j] == 0 || grid[i][j] == 2) return;

        res[i][j] = min(res[i][j], dist);

        grid[i][j] = 0;

        dfs(grid, i - 1, j, res, dist + 1);
        dfs(grid, i, j - 1, res, dist + 1);
        dfs(grid, i + 1, j, res, dist + 1);
        dfs(grid, i, j + 1, res, dist + 1);

        grid[i][j] = 1;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> result(grid.size(), vector<int>(grid[0].size(), INT_MAX));

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {

                if (grid[i][j] == 2) {
                    dfs(grid, i - 1, j, result, 1);
                    dfs(grid, i + 1, j, result, 1);
                    dfs(grid, i, j - 1, result, 1);
                    dfs(grid, i, j + 1, result, 1);
                }
            }
        }

        int ans = 0;

        for (int i = 0; i < result.size(); i++) {
            for (int j = 0; j < result[i].size(); j++) {
                if (result[i][j] == INT_MAX) {
                    if (grid[i][j] == 1) return -1;
                    else continue;
                }
                ans = max(ans, result[i][j]);
            }
        }

        return ans;
    }
};