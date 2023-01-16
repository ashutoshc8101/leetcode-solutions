class DSU {
    public:
        vector<int> parent;
        vector<int> rank;

        DSU(int n) {
            parent = vector<int>(n);
            rank = vector<int>(n);

            for (int i = 0; i < n; i++) {
                parent[i] = i;
                rank[i] = 0;
            }
        }

        int findParent(int i) {
            if (parent[i] == i) {
                return i;
            }

            return parent[i] = findParent(parent[i]);
        }

        void makeUnion(int a, int b) {
            int x = findParent(a);
            int y = findParent(b);

            if (x != y) {
                if (rank[x] > rank[y]) {
                    parent[y] = x;
                    rank[x] += rank[y];
                } else {
                    parent[x] = y;
                    rank[y] += rank[x];
                }
            }
        }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(vals.size(), vector<int>());

        DSU dsu(vals.size());

        for (vector<int> &edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        map<int, vector<int>> valToNode;

        for (int i = 0; i < vals.size(); i++) {
            valToNode[vals[i]].push_back(i);
        }

        int ans = 0;

        for (auto [value, nodes]: valToNode) {
            for (auto node: nodes) {
                for (auto neighbour : adjList[node]) {
                    if (vals[neighbour] <= vals[node]) {
                        dsu.makeUnion(node, neighbour);
                    }
                }
            }

            unordered_map<int, int> freqOfParent;

            for (auto node : nodes) {
                freqOfParent[dsu.findParent(node)]++;
            }

            for (auto it : freqOfParent) {
                int cnt = (it.second * (it.second + 1)) / 2;
                ans += cnt;
            }
        }

        return ans;
    }
};