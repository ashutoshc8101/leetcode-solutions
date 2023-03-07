class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int left = 0, right = A.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (A[mid] - mid - 1 >= k) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return k + left;
    }
};