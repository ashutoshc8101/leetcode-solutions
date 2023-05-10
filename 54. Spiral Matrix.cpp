class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        vector<int> result;

        int i = 0, j = 0, countY = 0, countX = 0;
        int directionX = 0, directionY = 0;

        int flag = 0;

        int count = 0;
        while (true) {
            if (flag == 0) {

                if (directionY == 0) {
                    if (m - countY == 0) break;
                    for (int z = 0; z < m - countY; z++) {
                        result.push_back(matrix[i][j]);
                        j++;
                    }
                    j--;
                    i++;
                    flag = 1;
                    directionY = 1;
                    countY++;
                } else {
                    if (m - countY == 0) break;
                    for (int z = 0; z < m - countY; z++) {
                        result.push_back(matrix[i][j]);
                        j--;
                    }
                    j++;
                    i--;
                    flag = 1;
                    directionY = 0;
                    countY++;
                }
            }

            if (flag == 1) {

                if (directionX == 0) {
                    if (n - countX - 1 == 0) break;
                    for (int y = 0; y < n - countX - 1; y++) {
                        result.push_back(matrix[i][j]);
                        i++;
                    }

                    i--;
                    j--;
                    flag = 0;
                    directionX = 1;
                    countX++;
                } else {
                    if (n - countX - 1 == 0) break;
                    for (int z = 0; z < n - countX - 1; z++) {
                        result.push_back(matrix[i][j]);
                        i--;
                    }
                    flag = 0;
                    i++;
                    j++;
                    directionX = 0;
                    countX++;
                }
            }
        }

        return result;
    }
};