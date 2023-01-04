class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int i = 0;
        int j = matrix.size() - 1;

        while (i <= j) {
            int mid = i + (j - i) / 2;

            if (matrix[mid][0] == target) {
                return true;
            }

            if (mid < matrix.size() - 1 && matrix[mid][0] < target && matrix[mid + 1][0] > target) {
                i = mid;
                cout << "Found in row " << i << endl;
                break;
            }

            if (mid == matrix.size() - 1 && matrix[mid][0] < target) {
                i = mid;
                cout << "Found in row " << i << endl;
                break;
            }

            if (matrix[mid][0] > target) {
                j = mid - 1;
            } else {
                i = mid + 1;
            }
        }

        int l = 0;
        int r = matrix[i].size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            if (matrix[i][mid] == target) {
                return true;
            }

            if (matrix[i][mid] > target) {
                r = mid - 1;
            }

            if (matrix[i][mid] < target) {
                l = mid + 1;
            }
        }

        return false;
    }
};