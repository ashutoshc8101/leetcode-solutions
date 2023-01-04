class Solution {
public:
    void permuteRec(vector<int>& nums, int l, int r, vector<vector<int>> &results) {
        if (l == r) {
            results.push_back(nums);
            return;
        }

        for (int i = l; i <= r; i++) {
            int temp = nums[i];
            nums[i] = nums[l];
            nums[l] = temp;

            permuteRec(nums, l + 1, r, results);

            temp = nums[i];
            nums[i] = nums[l];
            nums[l] = temp;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;

        permuteRec(nums, 0, nums.size() - 1, results);

        return results;
    }
};