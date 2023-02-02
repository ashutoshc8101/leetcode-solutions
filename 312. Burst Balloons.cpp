class Solution {
public:
    int burst(vector<int> &nums, int l, int r, vector<vector<int>> &dp) {
        if (l > r) {
            return 0;
        }

        if (dp[l][r] != -1) return dp[l][r];

        int maxCoins = 0;
        for (int i = l; i <= r; i++) {
            int coins = (
                (l == 0 ? 1 : nums[l - 1]) * nums[i] *
                ( r == nums.size() - 1 ? 1 : nums[r + 1])
            );
            coins += burst(nums, l, i - 1, dp);
            coins += burst(nums, i + 1, r, dp);

            maxCoins = max(maxCoins, coins);
        }

        return dp[l][r] = maxCoins;
    }

    int maxCoins(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size(), -1));
        return burst(nums, 0, nums.size() - 1, dp);
    }
};
