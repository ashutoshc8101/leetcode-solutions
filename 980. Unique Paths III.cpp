class Solution {
public:
    void dfs(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, int &result, int &cells, int steps) {
        if (grid[i][j] == 2) {
            if (cells == steps - 1) result++;
            return;
        }

        if (grid[i][j] == -1) return;

        visited[i][j] = true;

        if (i > 0 && !visited[i - 1][j]) {
            dfs(grid, i - 1, j, visited, result, cells, steps + 1);
        }

        if (j > 0 && !visited[i][j - 1]) {
            dfs(grid, i, j - 1, visited, result, cells, steps + 1);
        }

        if (i < grid.size() - 1 && !visited[i + 1][j]) {
            dfs(grid, i + 1, j, visited, result, cells, steps + 1);
        }

        if (j < grid[0].size() - 1 && !visited[i][j + 1]) {
            dfs(grid, i, j + 1, visited, result, cells, steps + 1);
        }

        visited[i][j] = false;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));

        int result = 0;
        int start_i, start_j;
        int cells = 0;

        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    start_i = i;
                    start_j = j;
                }

                if (grid[i][j] == 0) {
                    cells++;
                }
            }
        }

        dfs(grid, start_i, start_j, visited, result, cells, 0);

        return result;
    }
};