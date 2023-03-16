class Solution {
public:
    bool valid(vector<int> &quantities, int mid, int n) {
        for (int i = 0; i < quantities.size(); i++) {
            n -= ceil((double) quantities[i] / mid);
        }

        return n >= 0;
    }

    int minimizedMaximum(int n, vector<int>& quantities) {
        int left = 1, right = 1e7;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (valid(quantities, mid, n)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }

        }

        return left;
    }
};