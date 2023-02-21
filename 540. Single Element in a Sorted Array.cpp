class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            bool result = false;

            if (mid < nums.size() - 1 && nums[mid + 1] != nums[mid] && mid > 0 && nums[mid - 1] != nums[mid]) {
                result = true;
            }

            if (mid == 0 && nums[mid + 1] != nums[mid]) {
                result = true;
            }

            if (mid == nums.size() - 1 && nums[mid - 1] != nums[mid]) {
                result = true;
            }

            if (result) {
                return nums[mid];
            }

            if ((mid % 2 == 0 && nums[mid] == nums[mid - 1]) || (mid % 2 == 1 && nums[mid] == nums[mid + 1])) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }

        return 0;
    }
};