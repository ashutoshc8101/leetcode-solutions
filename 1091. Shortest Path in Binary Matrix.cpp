class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {

        if (grid[0][0] != 0 || grid[grid.size() - 1][grid.size() - 1] != 0) return -1;

        queue<vector<int>> q;
        q.push({0, 0});


        grid[0][0] = 1;

        while (!q.empty()) {
            int x = q.front()[0];
            int y = q.front()[1];
            q.pop();

            if (x == grid.size() - 1 && y == grid.size() - 1) {
                return grid[x][y];
            }

            if (x + 1 < grid.size() && grid[x + 1][y] == 0) {
                q.push({x + 1, y});
                grid[x + 1][y] = 1 + grid[x][y];
            }

            if (y + 1 < grid.size() && grid[x][y + 1] == 0) {
                q.push({ x, y + 1});
                grid[x][y + 1] = 1 + grid[x][y];
            }

            if (x > 0 && grid[x - 1][y] == 0) {
                q.push({x - 1, y});
                grid[x - 1][y] = 1 + grid[x][y];
            }

            if (y > 0 && grid[x][y - 1] == 0) {
                q.push({x, y - 1});
                grid[x][y - 1] = 1 + grid[x][y];
            }

            if (x + 1 < grid.size() && y + 1 < grid.size() && grid[x + 1][y + 1] == 0) {
                q.push({x + 1, y + 1});
                grid[x + 1][y + 1] = 1 + grid[x][y];
            }

            if (x + 1 < grid.size() && y > 0 && grid[x + 1][y - 1] == 0) {
                q.push({x + 1, y - 1});
                grid[x + 1][y - 1] = 1 + grid[x][y];
            }

            if (x > 0 && y + 1 < grid.size() && grid[x - 1][y + 1] == 0) {
                q.push({x - 1, y + 1});
                grid[x - 1][y + 1] = 1 + grid[x][y];
            }

            if (x > 0 && y > 0 && grid[x - 1][y - 1] == 0) {
                q.push({x - 1, y - 1});
                grid[x - 1][y - 1] = 1 + grid[x][y];
            }
        }

        return -1;
    }
};