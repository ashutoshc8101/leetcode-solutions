class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] > 0 && nums[i] <= N && nums[nums[i] - 1] != nums[i]) {
                cout << nums[i] << " : " << nums[nums[i] - 1] << endl;
                int temp = nums[i];
                int y = nums[i] - 1;
                nums[i] = nums[y];
                nums[y] = temp;
            }
        }

        for (int i = 0; i < N; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        return N + 1;
    }
};