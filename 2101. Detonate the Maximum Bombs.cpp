class Solution {
public:
    double dist(vector<int> a, vector<int> b) {
        return sqrt(pow(a[0] - b[0], 2) + pow(a[1] - b[1], 2));
    }

    int dfs(vector<vector<int>> &adjL, int i, vector<bool> &visited) {
        int result = 1;

        visited[i] = true;

        for (int v : adjL[i]) {
            if (!visited[v]) {
                result += dfs(adjL, v, visited);
            }
        }

        return result;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        vector<vector<int>> adjL(bombs.size(), vector<int>());

        for (int i = 0; i < bombs.size(); i++) {
            for (int j = 0; j < bombs.size(); j++) {
                if (i != j && dist(bombs[j], bombs[i]) <= (double) (bombs[j][2])) {
                    adjL[j].push_back(i);
                }
            }
        }

        vector<bool> visited(bombs.size(), false);

        int result = 0;

        for (int i = 0; i < bombs.size(); i++) {
            visited = vector<bool>(bombs.size(), false);
            result = max(result, dfs(adjL, i, visited));
        }

        return result;
    }
};