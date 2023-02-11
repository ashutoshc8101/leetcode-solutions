class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adjL(n);

        for (auto rd : redEdges) {
            adjL[rd[0]].push_back({rd[1], 1});
        }

        for (auto bE : blueEdges) {
            adjL[bE[0]].push_back({ bE[1], 2});
        }

        queue<vector<int>> q;

        vector<bool> visited1(n, false);
        vector<bool> visited2(n, false);

        q.push({0, 0, 0});

        vector<int> results(n, -1);

        while (!q.empty()) {
            vector<int> fr = q.front();
            q.pop();

            if (fr[1] == 1) {
                visited1[fr[0]] = true;
            } else if (fr[1] == 2) {
                visited2[fr[0]] = true;
            }

            if (results[fr[0]] == -1) {
                results[fr[0]] = fr[2];
            } else {
                results[fr[0]] = min(results[fr[0]], fr[2]);
            }

            for (auto v : adjL[fr[0]]) {
                if (v.second != fr[1]) {
                    if ((v.second == 1 && !visited1[v.first]) || (v.second == 2 && !visited2[v.first]) )
                    q.push({ v.first, v.second, fr[2] + 1 });
                }
            }
        }

        return results;
    }
};