class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> result(ratings.size(), 1);

        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                result[i] = 1 + result[i - 1];
            }
        }

        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                result[i] = max(result[i], 1 + result[i + 1]);
            }
        }

        int returnVal = 0;

        for (int i : result) {
            returnVal += i;
        }

        return returnVal;
    }
};