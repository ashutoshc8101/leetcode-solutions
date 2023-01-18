class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int currMaxSum = 0;
        int currMinSum = 0;
        int maxSum = INT_MIN;
        int minSum = INT_MAX;

        int sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            currMaxSum = max(nums[i], nums[i] + currMaxSum);
            currMinSum = min(nums[i], nums[i] + currMinSum);

            sum += nums[i];

            maxSum = max(maxSum, currMaxSum);
            minSum = min(minSum, currMinSum);
        }

        return maxSum > 0 ? max(maxSum, sum - minSum) : maxSum;
    }
};