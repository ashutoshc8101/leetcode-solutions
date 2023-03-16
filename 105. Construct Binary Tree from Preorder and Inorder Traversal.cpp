class Solution {
public:
    TreeNode* buildTreeRec(vector<int> &preorder, vector<int> &inorder, int i, int j, int m, int n) {
        if (i == j) return new TreeNode(preorder[i]);

        for (int k = m; k <= n; k++) {
            if (inorder[k] == preorder[i]) {
                return new TreeNode(inorder[k],
                    buildTreeRec(preorder, inorder, i + 1, i + k - m, m, k - 1),
                    buildTreeRec(preorder, inorder, i + k - m + 1, j, k + 1, n));
            }
        }

        return NULL;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeRec(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};