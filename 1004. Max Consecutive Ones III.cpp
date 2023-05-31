class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;

        int result = 0;

        int numOnes = 0;
        int numZeros = 0;

        while (j < nums.size()) {
            if (nums[j] == 1) {
                numOnes++;
            } else {
                numZeros++;
            }

            while (numZeros > k) {
                if (nums[i++] == 0) {
                    numZeros--;
                }
            }

            result = max(result, j - i + 1);
            j++;
        }

        return result;
    }
};