class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);

        bool nullNodeFound = false;

        while (!q.empty()) {
            int size = q.size();

            while (size--) {
                TreeNode* node = q.front();
                q.pop();

                if (nullNodeFound) {
                    if (node != NULL) {
                        return false;
                    }
                } else {
                    if (node == NULL) {
                        nullNodeFound = true;
                        continue;
                    }

                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }

        return true;
    }
};