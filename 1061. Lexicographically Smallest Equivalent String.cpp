class Solution {
public:
    char dfs(unordered_map<char, vector<char>> &adjL, char u, unordered_map<char, bool> &visited) {
        char minVal = u;
        visited[u] = true;
        for (char ch : adjL[u]) {
            if (visited[ch] == false) {
                minVal = min(minVal, dfs(adjL, ch, visited));
            }
        }

        return minVal;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        unordered_map<char, vector<char>> adjL;

        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] != s2[i]) {
                adjL[s1[i]].push_back(s2[i]);
                adjL[s2[i]].push_back(s1[i]);
            }
        }

        string result = "";

        for (char ch : baseStr) {
            unordered_map<char, bool> visited;
            result += dfs(adjL, ch, visited);
        }

        // for (auto m : adjL) {
        //     cout << m.first << " : ";

        //     for (char ch : m.second) {
        //         cout << ch << " ";
        //     }
        //     cout << endl;
        // }

        return result;
    }
};