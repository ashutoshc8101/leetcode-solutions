class TrieNode {
    public:
        vector<TrieNode*> children;
        int index = -1;
        vector<int> list;

        TrieNode() {
            children = vector<TrieNode*>(26, NULL);
            list = vector<int>();
        }
};

bool isPalindrome(string &s, int i, int j) {
    if (i >= j) return true;

    if (s[i] != s[j]) return false;

    return isPalindrome(s, i + 1, j - 1);
}

void addNode(TrieNode* root, string key, int index) {
    TrieNode* temp = root;

    for (int i = key.size() - 1; i >= 0; i--) {
        if (temp->children[key[i] - 'a'] == NULL) {
            temp->children[key[i] - 'a'] = new TrieNode();
        }

        if (isPalindrome(key, 0, i)) {
            temp->list.push_back(index);
        }

        temp = temp->children[key[i] - 'a'];
    }

    temp->list.push_back(index);
    temp->index = index;
}

void searchKey(TrieNode* root, vector<string> &words, int i, vector<vector<int>> &results) {
    TrieNode* temp = root;

    for (int j = 0; j < words[i].size(); j++) {
        if (temp->index >= 0 && temp->index != i && isPalindrome(words[i], j, words[i].size() - 1)) {
            results.push_back({i, temp->index});
        }

        temp = temp->children[words[i][j] - 'a'];

        if (temp == NULL) return;
    }

    for (int j : temp->list) {
        if (i != j) {
            results.push_back({i, j});
        }
    }
}

void printTrie(TrieNode* root) {
    if (root == NULL) return;

    for (int i = 0; i < root->children.size(); i++) {
        if (root->children[i] != NULL) {
            printTrie(root->children[i]);
        }
    }
}

class Solution {
public:
    vector<vector<int>> palindromePairs(vector<string>& words) {
        TrieNode* root = new TrieNode();
        vector<vector<int>> results;

        for (int i = 0; i < words.size(); i++) {
            addNode(root, words[i], i);
        }

        printTrie(root);

        for (int j = 0; j < words.size(); j++) {
            searchKey(root, words, j, results);
        }

        return results;
    }
};