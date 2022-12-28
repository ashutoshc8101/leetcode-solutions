class Solution {
public:
    void permute(vector<int> &nums, int l, int r, vector<vector<int>> &results) {
        if (l == r) {
            vector<int> vt(nums);
            results.push_back(vt);
            return;
        }

        unordered_set<int> uset;

        for (int i = l; i <= r; i++) {
            if (uset.find(nums[i]) != uset.end()) {
                continue;
            }

            uset.insert(nums[i]);

            // swap
            int temp = nums[l];
            nums[l] = nums[i];
            nums[i] = temp;

            permute(nums, l + 1, r, results);

            //swap back
            temp = nums[l];
            nums[l] = nums[i];
            nums[i] = temp;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> results;

        permute(nums, 0, nums.size() - 1,  results);

        return results;
    }
};