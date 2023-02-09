class Solution {
public:
    int trap(vector<int>& height) {
        const int N = height.size();
        int leftMax = 0;
        int rightMax = 0;

        vector<int> left(N);
        vector<int> right(N);

        for (int i = 0; i < N; i++) {
            leftMax = max(leftMax, height[i]);
            left[i] = leftMax;
        }

        for (int i = N - 1; i >= 0; i--) {
            rightMax = max(rightMax, height[i]);
            right[i] = rightMax;
        }

        int result = 0;

        for (int i = 0; i < N; i++) {
            result += min(left[i], right[i]) - height[i];
        }

        return result;
    }
};