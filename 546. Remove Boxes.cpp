class Solution {
public:
    int solveRec(vector<int> &boxes, int i, int r, vector<vector<vector<int>>> &dp, int count = 0) {
        if (i > r) {
            return 0;
        }

        if (dp[i][r][count] != -1) return dp[i][r][count];

        int iI = i;
        int countI = count;

        while (i < r && boxes[i] == boxes[i + 1]) {
            count += 1;
            i++;
        }

        count += 1;

        int ans = (count * count) + solveRec(boxes, i + 1, r, dp);

        for (int k = i + 1; k <= r; k++) {
            if (boxes[i] == boxes[k]) {
                ans = max(ans, solveRec(boxes, k, r, dp, count) + solveRec(boxes, i + 1, k - 1, dp));
            }
        }

        return dp[iI][r][countI] = ans;
    }

    int removeBoxes(vector<int>& boxes) {
        vector<vector<vector<int>>> dp(boxes.size() + 1,
            vector<vector<int>>(boxes.size() + 1,
            vector<int>(boxes.size() + 1, -1)));

        return solveRec(boxes, 0,  boxes.size() - 1, dp);
    }
};