class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int first = INT_MAX, second = INT_MAX;

        for (int k = 0; k < nums.size(); k++) {
            if (nums[k] <= first) {
                first = nums[k];
            } else if (nums[k] <= second) {
                second = nums[k];
            } else {
                return true;
            }
        }

        return false;
    }
};