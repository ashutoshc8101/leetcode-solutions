class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int result = 0;
        for (int i = 0; i < costs.size(); i++) {
            if (coins - costs[i] >= 0) {
                coins -= costs[i];
                result += 1;
            } else {
                break;
            }
        }

        return result;
    }
};