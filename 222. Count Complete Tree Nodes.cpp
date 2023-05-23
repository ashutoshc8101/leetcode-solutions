class Solution {
public:
    int countNodes(TreeNode* root) {
        TreeNode *leftNode = root, *rightNode = root;

        int leftH = 0, rightH = 0;
        while (leftNode) {
            leftNode = leftNode->left;
            leftH++;
        }

        while (rightNode) {
            rightNode = rightNode->right;
            rightH++;
        }

        if (rightH == leftH) {
            return pow(2, leftH) - 1;
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};