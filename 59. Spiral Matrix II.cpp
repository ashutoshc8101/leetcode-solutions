class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, 0));

        int i = 0, j = 0, countY = 0, countX = 0;
        int directionX = 0, directionY = 0;

        int flag = 0;
        int k = 1;
        int count = 0;
        while (true) {
            if (flag == 0) {

                if (directionY == 0) {
                    if (n - countY == 0) break;
                    for (int z = 0; z < n - countY; z++) {
                        matrix[i][j] = k++;
                        j++;
                    }
                    j--;
                    i++;
                    flag = 1;
                    directionY = 1;
                    countY++;
                } else {
                    if (n - countY == 0) break;
                    for (int z = 0; z < n - countY; z++) {
                        matrix[i][j] = k++;
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
                        matrix[i][j] = k++;
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
                        matrix[i][j] = k++;
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

        return matrix;
    }
};