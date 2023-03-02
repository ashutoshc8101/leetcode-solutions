class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int max_profit = 0;

        int j = 0;
        for (int i = 0; i <= arr.size() - 1; i++) {
            if (arr[i] < arr[j]) {
                j = i;
            }

            max_profit = max(max_profit, arr[i] - arr[j]);
        }

        return max_profit;
    }
};