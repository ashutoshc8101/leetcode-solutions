class Solution {
public:
    bool valid(vector<int> &nums, int mid, int k) {
        int total = 0;
        int count = 1;

        for (int i = 0; i < nums.size(); i++) {
            total += nums[i];

            if (total > mid) {
                total = nums[i];
                count++;

                if (count > k) {
                    return false;
                }
            }
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        vector<int> prefixSum(nums.size());

        int maxNum = nums[0];
        int totalSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            totalSum += nums[i];
            maxNum = max(maxNum, nums[i]);
        }

        if (k == 1) return totalSum;

        int left = maxNum, right = totalSum;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (valid(nums, mid, k)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }
};