class Solution {
public:
    int countOdds(int low, int high) {
        int result = (high - low) / 2;

        if (low % 2 == 1 || high % 2 == 1) {
            result += 1;
        }

        return result;
    }
};