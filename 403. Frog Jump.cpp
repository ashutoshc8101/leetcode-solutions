struct Node {
    int val = -1;
};

class Solution {
public:
    bool canCrossRec(vector<int> &stones, int i, int k,
    vector<unordered_map<int, Node>> &dp) {
        if (i == stones.size() - 1) {
            return true;
        }

        if (dp[i][k].val != -1) return dp[i][k].val;

        bool result = false;

        if (i == 0) {
            if (stones[1] - stones[0] == 1) {
                return canCrossRec(stones, 1, 1, dp);
            }

            return false;
        }

        for (int j = i + 1; j < stones.size(); j++) {
            if (stones[j] - stones[i] == k - 1) {
                dp[j][k - 1].val = canCrossRec(stones, j, k - 1, dp);
                result |= dp[j][k - 1].val;
            }

            if (stones[j] - stones[i] == k) {
                dp[j][k].val = canCrossRec(stones, j, k, dp);
                result |= dp[j][k].val;
            }

            if (stones[j] - stones[i] == k + 1) {
                dp[j][k + 1].val = canCrossRec(stones, j, k + 1, dp);
                result |= dp[j][k + 1].val;
            }
        }

        return dp[i][k].val = result;
    }

    bool canCross(vector<int>& stones) {
        vector<unordered_map<int, Node>> dp(stones.size() + 1);

        return canCrossRec(stones, 0, 1, dp);
    }
};
