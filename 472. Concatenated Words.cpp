class TrieNode {
    public:
        vector<TrieNode*> children;
        bool isEndOfWord = false;

        TrieNode() {
            children = vector<TrieNode*>(26, NULL);
        }
};

class Trie {
    public:
        TrieNode* root;

        Trie() {
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

        bool searchWord(string word) {
            TrieNode* temp = root;

            for (int i = 0; i < word.length(); i++) {
                if (temp->children[i] == NULL) return false;

                temp = temp->children[i];
            }

            return true;
        }
};

class Solution {
public:
    bool isConcatenated(Trie &trie, string word, int index, int countConcatenatedWords) {
        if (index == word.length())
            return countConcatenatedWords >= 2;

        TrieNode* ptr = trie.root;
        for (int i = index; i < word.length(); i++) {
            if (ptr->children[word[i] - 'a'] == NULL)
                return false;
            ptr = ptr->children[word[i] - 'a'];

            if (ptr->isEndOfWord)
                if (isConcatenated(trie, word, i + 1, countConcatenatedWords + 1))
                    return true;
        }

        return false;
    }

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        Trie trie;

        for (string word : words) {
            trie.addWord(word);
        }

        vector<string> results;
        for (string word : words) {
            if (isConcatenated(trie, word, 0, 0))
                results.push_back(word);
        }
        return results;
    }
};
