class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char, int> mp;

        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto m : mp) {
            pq.push({m.second, m.first});
        }

        string result = "";

        while (!pq.empty()) {
            pair<int, int> top1 = pq.top();
            pq.pop();

            result += top1.second;

            if (!pq.empty()) {
                pair<int, int> top2 = pq.top();
                pq.pop();
                result += top2.second;

                if (top2.first > 1) {
                    pq.push({ top2.first - 1, top2.second });
                }
            }

            if (top1.first > 1) {
                pq.push({top1.first - 1, top1.second});
            }
        }

        for (int i = 0; i < result.length() - 1; i++) {
            if (result[i + 1] == result[i]) return "";
        }

        return result;
    }
};