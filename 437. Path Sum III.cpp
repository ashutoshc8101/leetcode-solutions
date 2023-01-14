class Solution {
public:
    void preOrder(TreeNode* root, long long sum, long long targetSum, long long &count) {
        if (!root) return;

        if (sum - root->val == 0) {
            count++;
        }

        preOrder(root->left, sum - root->val, targetSum, count);
        preOrder(root->right, sum - root->val, targetSum, count);
    }

    int pathSum(TreeNode* root, long long targetSum) {
        long long count = 0;

        if (root) {
            preOrder(root, targetSum, targetSum, count);
            count += pathSum(root->left, targetSum);
            count += pathSum(root->right, targetSum);
        }

        return count;
    }
};