class Solution {
public:
    int getSum(vector<int> &BITree, int index) {
        int sum = 0;
        index = index + 1;

        while (index < BITree.size()) {
            sum += BITree[index];

            index += index & (-index);
        }

        return sum;
    }

    void updateBITree(vector<int> &BITree, int index, int val) {
        index = index + 1;

        while (index > 0) {
            BITree[index] += val;

            index += index & (-index);
        }
    }

    int index(vector<int> &nums, long long val) {
        int left = 0, right = nums.size() -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (nums[mid] >= val) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return left;
    }

    int reversePairs(vector<int>& arr) {
        vector<int> nums(arr);
        sort(nums.begin(), nums.end());
        vector<int> BITree(nums.size() + 1, 0);

        int result = 0;
        for (int i = 0; i < arr.size(); i++) {
            result += getSum(BITree, index(nums, 2L * arr[i] + 1));
            updateBITree(BITree, index(nums, arr[i]), 1);
        }

        return result;
    }
};