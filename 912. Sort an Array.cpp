class Solution {
public:

    void merge(vector<int> &nums, int l, int m, int r) {
        vector<int> temp(r - l + 1);

        int n1 = m - l + 1;
        int n2 = r - m;

        int i = 0, j = 0;
        int k = 0;
        while (i < n1 && j < n2) {
            if (nums[l + i] <= nums[m + j + 1]) {
                temp[k++] = nums[l + i];
                i++;
            } else {
                temp[k++] = nums[m + j + 1];
                j++;
            }
        }

        while (i < n1) {
            temp[k++] = nums[l + i];
            i++;
        }

        while (j < n2) {
            temp[k++] = nums[m + j + 1];
            j++;
        }

        for (int i = 0; i < temp.size(); i++) {
            nums[l + i] = temp[i];
        }
    }

    void mergesort(vector<int> &nums, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;

        mergesort(nums, left, mid);
        mergesort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        mergesort(nums, 0, nums.size() - 1);

        return nums;
    }
};