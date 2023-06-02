class Solution {
public:
    int dfs(vector<vector<int>> &adjL, int i, vector<bool> &visited) {
        visited[i] = true;

        int result = 1;

        for (int v : adjL[i]) {
            if (!visited[v]) {
                result += dfs(adjL, v, visited);
            }
        }

        return result;
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        vector<vector<int>> adjL(rooms.size(), vector<int>());

        for (int i = 0; i < rooms.size(); i++) {
            for (int idx : rooms[i]) {
                adjL[i].push_back(idx);
            }
        }

        int result = 0;
        vector<bool> visited(rooms.size(), false);

        result = dfs(adjL, 0, visited);

        return result == rooms.size();
    }
};