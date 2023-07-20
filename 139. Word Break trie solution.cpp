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

        void insert(string s) {
            TrieNode* temp = root;

            for (int i = 0; i < s.length(); i++) {
                if (temp->children[s[i] - 'a'] == NULL) {
                    temp->children[s[i] - 'a'] = new TrieNode();
                }

                temp = temp->children[s[i] - 'a'];
            }

            temp->isEndOfWord = true;
        }

        bool searchPrefix(string s) {
            TrieNode* temp = root;

            for (int i = 0; i < s.length(); i++) {
                if (temp->children[s[i] - 'a'] == NULL) {
                    return false;
                }

                temp = temp->children[s[i] - 'a'];
            }

            return true;
        }

        bool searchWord(string s) {
            TrieNode* temp = root;

            for (int i = 0; i < s.length(); i++) {
                if (temp->children[s[i] - 'a'] == NULL) {
                    return false;
                }

                temp = temp->children[s[i] - 'a'];
            }

            return temp->isEndOfWord;
        }
};

class Solution {
public:

    bool wordBreak(string s, vector<string>& wordDict) {
        // dp solution

        vector<bool> dp(s.length() + 1, false);
        unordered_map<string, int> ump;
        Trie trie;

        for (string word: wordDict) {
            ump[word]++;
            trie.insert(word);
        }

        for (int i = 0; i < s.length(); i++) {
            if (i == 0 || dp[i - 1]) {
                
                for (int j = i; j < s.length(); j++) {
                    string sbr = s.substr(i, j - i + 1);
                    
                    if (!trie.searchPrefix(sbr)) {
                        break;
                    }

                    if (ump.find(sbr) != ump.end()) {
                        dp[j] = true;

                        if (j == s.length() - 1) return true;
                    }
                }
            }
        }

        return false;
    }
};


