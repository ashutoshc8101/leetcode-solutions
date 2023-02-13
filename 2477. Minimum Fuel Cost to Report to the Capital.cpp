class Solution {
public:
    long long dfs(vector<vector<int>> &adjL, int u, long long &ans, int seats, vector<bool> &visited) {

        int people = 1;
        visited[u] = true;

        for (int v : adjL[u]) {
            if (!visited[v]) {
                people += dfs(adjL, v, ans, seats, visited);
            }
        }

        if (u > 0) {
            ans += people / seats;
            if (people % seats > 0) {
                ans += 1;
            }
        }

        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        vector<vector<int>> adjL(roads.size() + 1);

        for (vector<int> road : roads) {
            adjL[road[0]].push_back(road[1]);
            adjL[road[1]].push_back(road[0]);
        }

        vector<bool> visited(roads.size() + 1, false);

        long long ans = 0;
        dfs(adjL, 0, ans, seats, visited);

        return ans;
    }
};