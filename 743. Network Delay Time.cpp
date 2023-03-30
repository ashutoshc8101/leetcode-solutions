class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjL(n);

        for (int i = 0; i < times.size(); i++) {
            adjL[times[i][0] - 1].push_back({times[i][1] - 1, times[i][2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

        vector<int> dist(n, INT_MAX);

        pq.push(make_pair(0, k - 1));

        dist[k - 1] = 0;

        while (!pq.empty()) {
            int u = pq.top().second;
            pq.pop();

            for (pair<int, int> i : adjL[u]) {
                int v = i.first;
                int weight = i.second;

                if (dist[v] > dist[u] + weight) {
                    dist[v] = dist[u] + weight;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }

        int result = 0;

        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) return -1;

            result = max(result, dist[i]);
        }

        return result;
    }
};