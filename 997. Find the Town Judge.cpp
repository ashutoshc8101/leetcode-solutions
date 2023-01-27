class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj1(n + 1, vector<int>());
        vector<vector<int>> adj2(n + 1, vector<int>());

        for (vector<int> t : trust) {
            adj1[t[1]].push_back(t[0]);
            adj2[t[0]].push_back(t[1]);
        }

        for (int i = 1; i <= n; i++) {
            if (adj1[i].size() == n - 1 && adj2[i].size() == 0) {
                return i;
            }
        }

        return -1;
    }
};