class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {

        long long maxTime = 0;

        for (long long t : time) {
            maxTime = max(maxTime, (long long) t * totalTrips);
        }

        long long left = 0, right = maxTime;

        while (left <= right) {
            long long count = 0;

            long long mid = left + (right - left) / 2;

            for (int i = 0; i < time.size(); i++) {
                if (time[i] <= mid) {
                    count += mid / time[i];
                }
            }

            if (count >= totalTrips) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};