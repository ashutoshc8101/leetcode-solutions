class Solution {
public:
    int trailingZeroes(int n) {
        int count = n / 5;

        int temp = count;

        while (temp >= 5) {
            count += temp / 5;
            temp /= 5;
        }

        return count;
    }
};