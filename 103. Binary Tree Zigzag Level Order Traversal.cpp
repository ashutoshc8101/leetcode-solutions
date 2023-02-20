/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (!root) return vector<vector<int>>();

        stack<TreeNode*> s1, s2;
        vector<vector<int>> result;

        s1.push(root);

        while(s1.size() || s2.size()) {
            vector<int> row;
            if (s1.size()) {
                while (s1.size()) {
                    TreeNode* temp = s1.top();
                    row.push_back(temp->val);
                    s1.pop();

                    if (temp->left) s2.push(temp->left);
                    if (temp->right) s2.push(temp->right);
                }
            } else if (s2.size()) {
                while (s2.size()) {
                    TreeNode* temp = s2.top();
                    row.push_back(temp->val);
                    s2.pop();

                    if (temp->right) s1.push(temp->right);
                    if (temp->left) s1.push(temp->left);
                }
            }

            result.push_back(row);
        }

        return result;
    }
};