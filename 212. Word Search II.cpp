class TrieNode {
    public:
        vector<TrieNode*> children;
        bool isEndOfWord = false;

        TrieNode() {
            children = vector<TrieNode*>(26, NULL);
        }
};

void addWord(TrieNode* root, string word) {
    TrieNode* temp = root;

    for (int i = 0; i < word.size(); i++) {
        if (temp->children[word[i] - 'a'] == NULL) {
            temp->children[word[i] - 'a'] = new TrieNode();
        }

        temp = temp->children[word[i] - 'a'];
    }

    temp->isEndOfWord = true;
}

bool searchWord(TrieNode* root, string query) {
    TrieNode* temp = root;

    for (int i = 0; i < query.size(); i++) {
        if (temp->children[query[i] - 'a'] == NULL) {
            return false;
        }

        temp = temp->children[query[i] - 'a'];
    }

    return temp->isEndOfWord;
}

void dfs(vector<vector<char>> &board, int i, int j, TrieNode* root, string word, set<string> &results) {
    if (i < 0 || i == board.size() || j == board[0].size() || j < 0) {
        return;
    }

    if (board[i][j] == '.') return;

    if (root->children[board[i][j] - 'a'] == NULL) {
        return;
    }

    word += board[i][j];

    root = root->children[board[i][j] - 'a'];

    if (root->isEndOfWord) {
        results.insert(word);
    }

    char temp = board[i][j];
    board[i][j] = '.';
    dfs(board, i + 1, j, root, word, results);
    dfs(board, i, j + 1, root, word, results);
    dfs(board, i - 1, j, root, word, results);
    dfs(board, i, j - 1, root, word, results);
    board[i][j] = temp;
}

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();

        for (string word: words) {
            addWord(root, word);
        }

        set<string> st;

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[i].size(); j++) {
                dfs(board, i, j, root, "", st);
            }
        }

        vector<string> results;

        for (string s : st) {
            results.push_back(s);
        }

        return results;
    }
};