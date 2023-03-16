class Solution {
public:
    void preOrder(TreeNode* root, vector<int> &path, vector<vector<int>> &paths) {

        if (root == NULL) {
            return;
        }

        path.push_back(root->val);

        if (root->left == NULL && root->right == NULL) {
            paths.push_back(path);
            path.pop_back();
            return;
        }

        preOrder(root->left, path, paths);
        preOrder(root->right, path, paths);

        path.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        vector<vector<int>> paths;
        vector<int> path;

        preOrder(root, path, paths);


        int sum = 0;
        for (auto path : paths) {
            int num = 0;
            for (auto x : path) {
                num *= 10;
                num += x;
            }

            sum += num;
        }

        return sum;
    }
};