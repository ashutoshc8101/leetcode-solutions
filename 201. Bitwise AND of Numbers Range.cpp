class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int result = 0;

        for (int i = 30; i >= 0; i--) {
            if ((left & (1 << i)) == (right & (1 << i))) {
                result |= (left & (1 << i));
            } else {
                break;
            }
        }

        return result;
    }
};