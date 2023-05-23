class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;

        int lastOcc = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if ((mid + 1 < nums.size() && nums[mid] == target && nums[mid + 1] > target)
            || (mid == nums.size() - 1 && nums[mid] == target)) {
                lastOcc = mid;
                break;
            }

            if (mid + 1 < nums.size() && nums[mid] == target && nums[mid + 1] == target || (nums[mid] < target)) {
                left = mid + 1;
            }

            if (nums[mid] > target) {
                right = mid - 1;
            }
        }

        left = 0, right = nums.size() - 1;

        int firstOcc = -1;

        while(left <= right) {
            int mid = left + (right - left) / 2;

            if ((mid > 0 && nums[mid] == target && nums[mid - 1] < target)
            || (mid == 0 && nums[mid] == target)) {
                firstOcc = mid;
                break;
            }

            if (mid > 0 && nums[mid] == target && nums[mid - 1] == target || (nums[mid] > target)) {
                right = mid - 1;
            }

            if (nums[mid] < target) {
                left = mid + 1;
            }
        }

        return vector<int>({firstOcc, lastOcc});
    }
};