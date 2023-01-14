class TrieNode {
    public:
        vector<TrieNode*> children;
        bool isEndOfWord = false;

        TrieNode() {
            children = vector<TrieNode*>(26, NULL);
        }
};

class WordDictionary {
public:
    TrieNode* root;

    WordDictionary() {
        root = new TrieNode();
    }

    void addWord(string word) {
        TrieNode* temp = root;

        for (int i = 0; i < word.length(); i++) {
            if (temp->children[word[i] - 'a'] == NULL) {
                temp->children[word[i] - 'a'] = new TrieNode();
            }

            temp = temp->children[word[i] - 'a'];
        }

        temp->isEndOfWord = true;
    }

    bool search(string word) {
        return searchWithDots(root, word, 0);
    }

    bool searchWithDots(TrieNode* root, string word, int l) {
        TrieNode* temp = root;

        for (int i = l; i < word.length(); i++) {
            if (word[i] == '.') {
                bool result = false;
                for (TrieNode* child: temp->children) {
                    if (child != NULL)
                        result |= searchWithDots(child, word, i + 1);
                }

                return result;
            } else {
                if (temp->children[word[i] - 'a'] == NULL) {
                    return false;
                }

                temp = temp->children[word[i] - 'a'];
            }
        }

        return temp->isEndOfWord;
    }
};