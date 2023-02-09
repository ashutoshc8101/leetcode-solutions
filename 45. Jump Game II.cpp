class Solution {
public:
    long long solve(vector<int>& nums, int i, int target, vector<int> &dp) {

        if (i == target) {
            return 0;
        }

        if (i > target) {
            return INT_MAX - 1;
        }

        if (dp[i] != -1) return dp[i];

        long long jumps = INT_MAX;

        for (int j = 1; j <= nums[i]; j++) {
            jumps = min(1 + solve(nums, i + j, target, dp), jumps);
        }

        return dp[i] = jumps;
    }

    int jump(vector<int>& nums) {
        int target = nums.size() - 1;

        vector<int> dp(nums.size(), -1);

        return solve(nums, 0, target, dp);
    }
};