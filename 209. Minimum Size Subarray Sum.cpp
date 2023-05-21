class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i = 0, j = 0;
        int minLength = INT_MAX;

        vector<int> prefixSum(nums.size() + 1, 0);

        prefixSum[0] = 0;
        for (int i = 0; i < nums.size(); i++) {
            prefixSum[i + 1] += nums[i] + prefixSum[i];
        }

        while (j < prefixSum.size()) {
            if (prefixSum[j] - prefixSum[i] < target) {
                j++;
            } else {
                minLength = min(j - i, minLength);
                i++;
            }
        }

        return minLength == INT_MAX ? 0 : minLength;
    }
};