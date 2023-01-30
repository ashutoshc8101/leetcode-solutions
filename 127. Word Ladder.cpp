class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;

        for (string word : wordList) {
            st.insert(word);
        }

        queue<pair<string, int>> q;
        q.push({beginWord, 1});

        unordered_map<string, bool> visited;
        visited[beginWord] = true;

        while (!q.empty()) {
            int size = q.size();

            for (int i = 0; i < size; i++) {
                string s = q.front().first;
                int count = q.front().second;
                q.pop();

                visited[s] = true;

                if (s == endWord) {
                    return count;
                }

                for (int k = 0; k < s.size(); k++) {
                    for (int j = 'a'; j <= 'z'; j++) {
                        string str(s);
                        str[k] = j;

                        if (st.find(str) != st.end() && !visited[str]) {
                            q.push({str, count + 1});
                        }
                    }
                }
            }
        }

        return 0;
    }
};