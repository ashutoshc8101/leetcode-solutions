class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        vector<unordered_map<long long, int>> dp(nums.size());
        int res = 0;

        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                long long diff = (long long) nums[j] - nums[i];

                if (dp[i].find(diff) != dp[i].end()) {
                    dp[j][diff] += 1 + dp[i][diff];
                    res += dp[i][diff];
                } else {
                    dp[j][diff] += 1;
                }
            }
        }    

        return res;
    }
};