class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int i = 0, j = 0;

        int numOnes = 0, numZeros = 0;

        int result = 0;

        while (j < nums.size()) {
            if (nums[j] == 1) {
                numOnes++;
            } else {
                numZeros++;
            }

            while (numZeros > 1) {
                if (nums[i++] == 0) {
                    numZeros--;
                }
            }

            result = max(result, j - i + 1);
            j++;
        }

        return result - 1;
    }
};