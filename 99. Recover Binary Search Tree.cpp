class Solution {
public:
    void inOrder(TreeNode* root, stack<TreeNode*> &st) {
        if (!root) return;

        inOrder(root->left, st);
        if (!st.empty() && st.top()->val > root->val) {
            int temp = root->val;
            root->val = st.top()->val;
            st.top()->val = temp;
        }

        while (!st.empty()) {
            st.pop();
        }

        st.push(root);
        inOrder(root->right, st);
    }

    void inOrder2(TreeNode* root, int &n) {
        if (!root) return;

        inOrder2(root->left, n);
        n++;
        inOrder2(root->right, n);
    }

    void recoverTree(TreeNode* root) {
        stack<TreeNode*> st;
        int n = 0;
        inOrder2(root, n);

        while (n--) {
            inOrder(root, st);

            while (!st.empty()) {
                st.pop();
            }
        }
    }
};