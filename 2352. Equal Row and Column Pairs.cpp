class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        map<vector<int>, int> ump1;
        map<vector<int>, int> ump2;

        for (int i = 0; i < grid.size(); i++) {
            ump1[grid[i]]++;
        }

        for (int j = 0; j < grid.size(); j++) {
            vector<int> vt;
            for (int i = 0; i < grid.size(); i++) {
                vt.push_back(grid[i][j]);
            }
            ump2[vt]++;
        }

        int result = 0;

        for (auto m : ump2) {
            if (ump1.find(m.first) != ump1.end()) {
                result += ump1[m.first] * m.second;
            }
        }

        return result;
    }
};