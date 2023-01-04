class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size() - 1;

        while (j > i) {
            if (numbers[i] + numbers[j] == target) {
                return vector<int>({i + 1, j + 1});
            } else if (numbers[i] + numbers[j] > target) {
                j--;
            } else {
                i++;
            }
        }

        return vector<int>({i, j});
    }
};