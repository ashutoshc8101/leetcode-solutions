class Solution {
public:
    const int NO_CAMERA = 0, HAS_CAMERA = 1, COVERED = 2;

    int dfs(TreeNode* root, int &ans) {
        if (!root) return COVERED;

        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);

        if (left == NO_CAMERA || right == NO_CAMERA) {
            ans++;
            return HAS_CAMERA;
        } else if (left == HAS_CAMERA || right == HAS_CAMERA) {
            return COVERED;
        }

        return NO_CAMERA;
    }

    int minCameraCover(TreeNode* root) {
        int ans = 0;

        if (dfs(root, ans) == 0) ans++;

        return ans;
    }
};
