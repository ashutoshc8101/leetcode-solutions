class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int dp[366] = {};

        unordered_set<int> st;

        for (auto day: days) {
            st.insert(day);
        }


        for (int i = 1; i <= 365; ++i) {
            if (st.find(i) == st.end()) dp[i] = dp[i - 1];
            else {
                dp[i] = min({ dp[i - 1] + costs[0], dp[max(0, i - 7)] + costs[1], dp[max(0, i - 30)] + costs[2]});
            }
        }

        return dp[365];
    }
};