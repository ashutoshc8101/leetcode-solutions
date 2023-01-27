class Solution {
public:
    void dfs(vector<vector<int>> &adjL, int u, int dist, vector<int> &distances, vector<bool> &visited) {
        distances[u] = dist;
        visited[u] = true;
        for (int v : adjL[u]) {
            if (!visited[v])
                dfs(adjL, v, dist + 1, distances, visited);
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        vector<vector<int>> adjL(edges.size(), vector<int>());
        vector<int> dist1(edges.size(), -1);
        vector<int> dist2(edges.size(), -1);

        for (int i = 0; i < edges.size(); i++) {
            if (edges[i] != -1)
                adjL[i].push_back(edges[i]);
        }

        vector<bool> visited1(edges.size(), false);
        vector<bool> visited2(edges.size(), false);
        dfs(adjL, node1, 0, dist1, visited1);
        dfs(adjL, node2, 0, dist2, visited2);

        int minDistance = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < edges.size(); i++) {
            if (dist1[i] != -1 && dist2[i] != -1) {
                if (max(dist1[i], dist2[i]) < minDistance) {
                    minDistance = max(dist1[i], dist2[i]);
                    minIndex = i;
                }
            }
        }

        return minIndex;
    }
};