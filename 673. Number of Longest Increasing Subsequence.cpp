class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> len(nums.size(), 0);
        vector<int> count(nums.size(), 0);

        int max_count = 0;
        int max_length = 0;

        for (int i = 0; i < nums.size(); i++) {
            len[i] = 1;
            count[i] = 1;

            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (len[i] == len[j] + 1) count[i] += count[j];

                    if (len[i] < len[j] + 1) {
                        len[i] = len[j] + 1;
                        count[i] = count[j];
                    }
                }
            }

            if (len[i] == max_length) {
                max_count += count[i];
            }

            if (len[i] > max_length) {
                max_length = len[i];
                max_count = count[i];
            }
        }

        return max_count;
    }
};