class NumArray {
public:
    vector<int> prefixSum;

    NumArray(vector<int>& nums) {
        prefixSum = vector<int>(nums.size(), 0);
        prefixSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i] = nums[i] + prefixSum[i - 1];
        }
    }

    int sumRange(int left, int right) {
        return prefixSum[right] - (left == 0 ? 0 : prefixSum[left - 1]);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */