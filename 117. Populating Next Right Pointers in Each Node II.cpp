class Solution {
public:
    Node* connect(Node* root) {
        if (root == NULL) return NULL;

        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                Node* temp = q.front();
                q.pop();

                if (temp != NULL) {
                    temp->next = q.front();
                    if (temp->left) q.push(temp->left);
                    if (temp->right) q.push(temp->right);
                } else if (!q.empty()) q.push(NULL);
            }
        }

        return root;
    }
};