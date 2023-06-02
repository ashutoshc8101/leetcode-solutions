class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<TreeNode*> q;

        q.push(root);

        int maxSumLevel = 1;
        int maxSum = root->val;

        int level = 1;

        while (!q.empty()) {
            int size = q.size();

            int levelSum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* front = q.front();

                levelSum += front->val;

                q.pop();

                if (front->left) q.push(front->left);

                if (front->right) q.push(front->right);
            }

            if (levelSum > maxSum) {
                maxSum = levelSum;
                maxSumLevel = level;
            }

            level++;
        }

        return maxSumLevel;
    }
};