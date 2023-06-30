class Solution {
public:
    long long maxStrength(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];

        sort(nums.begin(), nums.end(), greater<int>());

        long long running = 1;
        int i = 0;
        bool zeros = false;
        bool nonPositives = true;
        for (; i < nums.size(); i++) {
            if (nums[i] > 0) {
                running *= nums[i];
                nonPositives = false;
            } else if (nums[i] == 0) {
                zeros = true;
            } else if (nums[i] < 0) {
                break;
            }
        }

        if (nums.size() == i && nonPositives) {
            return 0;
        }

        if (nums.size() - i == 1) {
            if (zeros && nonPositives) return 0;
        }

        if ((nums.size() - i) % 2 == 1) {
            i++;
        }

        for (; i < nums.size(); i++) {
            running *= nums[i];
        }

        return running;
    }
};