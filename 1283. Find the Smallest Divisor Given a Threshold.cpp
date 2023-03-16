class Solution {
public:
    bool valid(vector<int>& nums, int threshold, int divisor) {
        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += ceil((double) nums[i] / divisor);

            if (sum > threshold) {
                return false;
            }
        }

        return true;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e7;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (valid(nums, threshold, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};