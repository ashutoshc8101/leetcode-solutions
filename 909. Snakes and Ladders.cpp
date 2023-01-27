class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        queue<pair<int, int>> q;

        int n = board.size();

        q.push({0, 0});

        int minSteps = INT_MAX;
        vector<bool> visited(n * n, false);
        visited[0] = true;

        while (q.size()) {
            pair<int, int> pa = q.front();
            q.pop();

            int p = pa.first;

            if (p == n * n - 1) {
                minSteps = min(minSteps, pa.second);
            };

            for (int i = p + 1; i <= min(p + 6, n * n - 1); i++) {
                int a = n - 1 - i / n;
                int b = (i / n) % 2 == 0 ? i % n : n - 1 - (i % n);

                int dest = board[a][b] - 1;

                if (board[a][b] == -1) {
                    dest = i;
                }

                if (!visited[dest]) {
                    visited[dest] = true;
                    q.push({dest, pa.second + 1});
                }
            }
        }

        return minSteps == INT_MAX ? -1 : minSteps;
    }
};
