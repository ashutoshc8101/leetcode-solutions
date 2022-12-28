class Solution {
public:
    void permute(vector<int> &nums, int l, int r, int &result)
    {
        // Base case
        if (l == r) {
            if (nums[l] % (l + 1) == 0 || (l + 1) % nums[l] == 0) {
                result++;
            }
        } else {
            // Permutations made
            for (int i = l; i <= r; i++) {
                if (nums[i] % (l + 1) == 0 || (l + 1) % nums[i] == 0) {
                    // Swapping done
                    int temp = nums[l];
                    nums[l] = nums[i];
                    nums[i] = temp;

                    permute(nums, l + 1, r, result);

                    temp = nums[l];
                    nums[l] = nums[i];
                    nums[i] = temp;
                }
            }
        }
    }

    int countArrangement(int n) {
        int result = 0;
        vector<int> nums(n);

        for (int i = 0; i < n; i++) {
            nums[i] = i + 1;
        }

        permute(nums, 0, n - 1, result);

        return result;
    }
};