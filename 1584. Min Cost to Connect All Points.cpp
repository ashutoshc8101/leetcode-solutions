class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> graph(points.size(), vector<int>(points.size(), 0));

        for (int i = 0; i < points.size(); i++) {
            for (int j = 0;j < points.size(); j++) {
                graph[i][j] = abs(points[i][0] - points[j][0]) + abs(points[j][1] - points[i][1]);
            }
        }

        vector<int> dist(points.size(), INT_MAX);
        vector<int> mset(points.size(), false);
        vector<int> parent(points.size());

        dist[0] = 0;
        parent[0] = -1;

        int res = 0;

        for (int count = 0; count < points.size() - 1; count++) {
            int u = -1;
            int min = INT_MAX;

            for (int i = 0; i < points.size(); i++) {
                if (mset[i] == false && dist[i] < min) {
                    u = i;
                    min = dist[i];
                }
            }


            mset[u] = true;

            for (int i = 0; i < points.size(); i++) {
                if (graph[u][i] != 0 && mset[i] == false && graph[u][i] < dist[i]) {
                    parent[i] = u;
                    if (dist[i] != INT_MAX) {
                        res -= dist[i];
                    }

                    dist[i] = graph[u][i];
                    res += dist[i];
                }
            }
        }

        return res;
    }
};