class Solution {
public:
    long long matrixSumQueries(int n, vector<vector<int>>& queries) {
        int rows = n, columns = n;
        long long ans = 0;

        unordered_set<int> rowsM, columnsM;

        for (int i = queries.size() - 1; i >= 0; i--) {
            if (queries[i][0] == 0) {
                if (rowsM.find(queries[i][1]) == rowsM.end()) {
                    ans += columns * queries[i][2];
                    rows -= 1;
                    rowsM.insert(queries[i][1]);
                }
            } else {
                if (columnsM.find(queries[i][1]) == columnsM.end()) {
                    ans += rows * queries[i][2];
                    columns -= 1;
                    columnsM.insert(queries[i][1]);
                }
            }
        }

        return ans;
    }
};