class Solution {
public:
    void solveRec(vector<int> &nums, int i, int sum, int k, vector<int> &result, set<vector<int>> &results) {
        if (k == 0 && sum == 0) results.insert(result);

        if (i == nums.size() || k < 0 || sum < 0) return;

        solveRec(nums, i + 1, sum, k, result, results);
        result.push_back(nums[i]);
        solveRec(nums, i + 1, sum - nums[i], k - 1, result, results);
        result.pop_back();
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums({1, 2, 3, 4, 5, 6, 7, 8, 9});

        set<vector<int>> results;

        vector<int> result;

        solveRec(nums, 0, n, k, result, results);

        vector<vector<int>> returnVector;

        for (auto v : results) returnVector.push_back(v);

        return returnVector;
    }
};