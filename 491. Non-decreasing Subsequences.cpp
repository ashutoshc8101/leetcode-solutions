class Solution {
public:
    void solve(vector<int> &nums, int i, int last, vector<int> &result, vector<vector<int>> &results) {
        if (i == nums.size()) {
            if (result.size() > 1)
                results.push_back(result);
            return;
        };

        if (nums[i] >= last) {
            result.push_back(nums[i]);
            solve(nums, i + 1, nums[i], result, results);
            result.pop_back();
        }

        solve(nums, i + 1, last, result, results);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<vector<int>> results;
        vector<int> result;

        solve(nums, 0, INT_MIN, result, results);

        set<vector<int>> st;

        for (auto r : results) {
            st.insert(r);
        }

        results = vector<vector<int>>();

        for (auto s : st) {
            results.push_back(s);
        }

        return results;
    }
};