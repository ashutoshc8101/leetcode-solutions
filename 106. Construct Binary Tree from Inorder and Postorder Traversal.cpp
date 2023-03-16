class Solution {
public:
    TreeNode* buildTreeRec(vector<int> &inorder, vector<int> &postorder, int i, int j, int m, int n) {
        if (i == j) return new TreeNode(inorder[i]);

        for (int k = i; k <= j;k++) {
            if (postorder[n] == inorder[k]) {
                return new TreeNode(inorder[k], buildTreeRec(inorder, postorder, i, k - 1, m, m + k - i - 1), buildTreeRec(inorder, postorder, k + 1, j, m + k - i, n - 1));
            }
        }

        return NULL;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTreeRec(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};