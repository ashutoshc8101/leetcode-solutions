class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int result = 0;
        int j = 0;
        for (int i = 1; i < colors.size(); i++) {
            if (colors[i] == colors[j]) {
                result += min(neededTime[i], neededTime[j]);

                if (neededTime[j] > neededTime[i]) {
                    continue;
                }
            }
            j = i;
        }

        return result;
    }
};