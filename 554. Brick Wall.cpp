class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> ump;
        int maxVal = 0;

        for (int i = 0; i < wall.size(); i++) {
            int sum = 0;
            for (int j = 0; j < wall[i].size() - 1; j++) {
                sum += wall[i][j];
                ump[sum]++;
                maxVal = max(maxVal, ump[sum]);
            }
        }

        return wall.size() - maxVal;
    }
};