class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> mp;
        priority_queue<pair<int, char>> pq;

        for (int i = 0; i < s.length(); i++) {
            mp[s[i]]++;
        }

        for (auto m : mp) {
            pq.push({m.second, m.first});
        }

        pair<int, char> last = {-1, '$'};

        int count = 0;

        while (!pq.empty()) {
            pair<int, char> curr = pq.top();

            if (last.first == curr.first) {
                last.first--;
                count++;
                if (last.first > 0)
                    pq.push(last);
            }
            last = curr;
            pq.pop();
        }

        return count;
    }
};