class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        unordered_set<string> ust;

        for (string str : bank) ust.insert(str);

        queue<pair<string, int>> q;
        q.push({startGene, 0});

        unordered_map<string, bool> visited;

        int result = INT_MAX;

        while (!q.empty()) {
            pair<string, int> top = q.front();
            q.pop();

            if (top.first == endGene) {
                result = min(result, top.second);
                continue;
            }

            visited[top.first] = true;

            for (char ch : {'A', 'C', 'G', 'T'}) {
                for (int i = 0; i < top.first.length(); i++) {
                    string str = top.first;
                    str[i] = ch;
                    if (!visited[str] && ust.find(str) != ust.end()) {
                        q.push({ str, top.second + 1 });
                    }
                }
            }

        }

        return result == INT_MAX ? -1 : result;
    }
};