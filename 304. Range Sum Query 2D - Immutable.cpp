class NumMatrix {
public:
    vector<vector<int>> prefixSumMatrix;

    NumMatrix(vector<vector<int>>& matrix) {
        prefixSumMatrix = vector<vector<int>>(matrix.size(), vector<int>(matrix[0].size()));

        for (int i = 0; i < matrix.size(); i++) {
            int sum = 0;
            for (int j = 0; j < matrix[i].size(); j++) {
                sum += matrix[i][j];
                prefixSumMatrix[i][j] = sum;
            }
        }

        for (int j = 0; j < matrix[0].size(); j++) {
            int sum = 0;
            for (int i = 0; i < matrix.size(); i++) {
                sum += prefixSumMatrix[i][j];
                prefixSumMatrix[i][j] = sum;
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {

        int result = 0;

        result += prefixSumMatrix[row2][col2];

        if (row1 > 0) {
            result -= prefixSumMatrix[row1 - 1][col2];
        }

        if (col1 > 0) {
            result -= prefixSumMatrix[row2][col1 - 1];
        }

        if (row1 > 0 && col1 > 0) {
            result += prefixSumMatrix[row1 - 1][col1 - 1];
        }

        // for (int i = 0; i < prefixSumMatrix.size(); i++) {
        //     for (int j = 0; j < prefixSumMatrix[0].size(); j++) {
        //         cout << prefixSumMatrix[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return result;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */