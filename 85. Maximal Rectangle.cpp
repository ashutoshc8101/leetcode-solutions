class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int maxArea = 0;
        vector<int> left(matrix[0].size(), 0);
        vector<int> right(matrix[0].size(), matrix[0].size());
        vector<int> height(matrix[0].size(), 0);

        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    height[j]++;
                } else {
                    height[j] = 0;
                }
            }

            int cleft = 0;
            for (int j = 0; j < matrix[0].size(); j++) {
                if (matrix[i][j] == '1') {
                    left[j] = max(cleft, left[j]);
                } else {
                    left[j] = 0;
                    cleft = j + 1;
                }
            }

            int c_right = matrix[0].size();

            for (int j = matrix[0].size() - 1; j >= 0; j--) {
                if (matrix[i][j] == '1') {
                    right[j] = min(right[j], c_right);
                } else {
                    right[j] = matrix[0].size();
                    c_right = j;
                }
            }

            for (int j = 0; j < matrix[0].size(); j++) {
                maxArea = max(maxArea, (right[j] - left[j]) * height[j]);
            }
        }

        return maxArea;
    }
};
