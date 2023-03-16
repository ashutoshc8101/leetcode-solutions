class Solution {
public:
    bool valid(vector<int> &bloomDay, int mid, int m, int k) {
        int bouquets = 0;
        int j = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= mid) {
                j++;
            } else {
                j = 0;
            }

            if (j == k) {
                bouquets++;
                j = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        if (bloomDay.size() < (long long) m * k) return -1;

        int left = 1, right = 1e9;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (valid(bloomDay, mid, m, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};