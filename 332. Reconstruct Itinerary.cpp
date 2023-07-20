class Solution {
public:
    void dfs(string u, unordered_map<string, vector<string>> &adjL,
        unordered_map<string, int> &outdegree, vector<string> &result) {
            while (outdegree[u] > 0) {
                dfs(adjL[u][--outdegree[u]], adjL, outdegree, result);
            }

            result.push_back(u);   
        }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string, vector<string>> adjL;
        unordered_map<string, int> outdegree;

        for (auto ticket: tickets) {
            adjL[ticket[0]].push_back(ticket[1]);
            outdegree[ticket[0]]++;
        }

        for (auto m : adjL) {
            sort(adjL[m.first].begin(), adjL[m.first].end(), greater<string>());
        }

        vector<string> result;

        dfs("JFK", adjL, outdegree, result);

        reverse(result.begin(), result.end());

        return result;
    }
};