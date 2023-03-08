class Solution {
public:
    long long minEatingSpeed(vector<int>& piles, int h) {
        long long maxK = 0;
        for (int i = 0; i < piles.size(); i++) {
            maxK = max(maxK, (long long) piles[i]);
        }

        long long left = 1, right = maxK;

        while (left <= right) {
            long long mid = left + (right - left) / 2;

            long long hrs = 0;
            for (int i = 0; i < piles.size(); i++) {
                hrs += piles[i] / mid;
                if (piles[i] % mid > 0) {
                    hrs++;
                }
            }

            if (hrs > h) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return left;
    }
};