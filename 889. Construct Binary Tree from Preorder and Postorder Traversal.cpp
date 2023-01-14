class Solution {
public:
    TreeNode* solve(vector<int> &preorder, vector<int> &postorder, int i, int j, int p, int q) {
        if (i > j) {
            return NULL;
        }
        if (i == j) {
            return new TreeNode(preorder[i]);
        }

        TreeNode* root = new TreeNode(preorder[i]);
        int leftRoot = i + 1;
        int rightRoot = q - 1;

        int k = 0;

        int z = i;
        for (; z <= j; z++) {
            if (preorder[z] == postorder[rightRoot]) {
                break;
            }
        }

        int y = q;
        for (;y >= 0; y--) {
            if (postorder[y] == preorder[leftRoot]) {
                break;
            }
        }

        cout << leftRoot << " : " << z - 1 << " : " << j << endl;
        cout << p << " : " << y << " : " << q  - 1<< endl;

        root->left = solve(preorder, postorder, leftRoot, z - 1, p, y);
        root->right = solve(preorder, postorder, z, j, y + 1, q - 1);
        return root;
    }

    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        if (preorder.size() == 2) {
            TreeNode* root = new TreeNode(preorder[0]);
            root->left = new TreeNode(preorder[1]);
            return root;
        }

        return solve(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }
};