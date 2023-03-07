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
    string inOrder(TreeNode* root, unordered_map<string, vector<TreeNode*>> &ump) {
        if (root == NULL) return "NULL";

        string str = to_string(root->val) + ", " +
        inOrder(root->left, ump) + ", " +
        inOrder(root->right, ump);

        ump[str].push_back(root);

        return str;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, vector<TreeNode*>> ump;

        inOrder(root, ump);

        vector<TreeNode*> result;

        for (auto m : ump) {
            if (m.second.size() > 1) {
                result.push_back(m.second[1]);
            }
        }

        return result;
    }
};