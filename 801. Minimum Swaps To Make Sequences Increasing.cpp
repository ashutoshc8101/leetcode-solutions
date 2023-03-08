class Solution {
public:
    int minSwapRec(vector<int>& nums1, vector<int>& nums2, int i, int prev1, int prev2, int swapped, vector<vector<int>> &dp) {
        if (i == nums1.size()) {
            return 0;
        }

        if (dp[i][swapped] != -1) return dp[i][swapped];

        int min1 = INT_MAX;

        if (prev1 < nums1[i] && prev2 < nums2[i]) {
            min1 = minSwapRec(nums1, nums2, i + 1, nums1[i], nums2[i], 0, dp);
        }

        if (nums2[i] > prev1 && nums1[i] > prev2) {
            int temp = nums1[i];
            nums1[i] = nums2[i];
            nums2[i] = temp;

            min1 = min(min1, 1 + minSwapRec(nums1, nums2, i + 1, nums1[i], nums2[i], 1, dp));

            temp = nums1[i];
            nums1[i] = nums2[i];
            nums2[i] = temp;
        }

        return dp[i][swapped] = min1;
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size(), vector<int>(2, -1));
        return minSwapRec(nums1, nums2, 0, -1, -1, 0, dp);
    }
};