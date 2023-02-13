class Solution {
public:
    int solveRec(vector<int> &arr, int left, int right, vector<vector<int>> &dp) {
        if (left >= right) {
            return 0;
        }

        if (dp[left][right] != -1) return dp[left][right];

        int result = INT_MAX;
        for (int k = left; k < right; k++) {
            int a = arr[left];

            for (int m = left; m <= k; m++) {
                a = max(a, arr[m]);
            }

            int b = arr[k + 1];

            for (int n = k + 1; n <= right; n++) {
                b = max(b, arr[n]);
            }

            result = min(result, a * b + solveRec(arr, left, k, dp) +
            solveRec(arr, k + 1, right, dp));
        }

        return dp[left][right] = result;
    }

    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(), -1));

        return solveRec(arr, 0, arr.size() - 1, dp);
    }
};