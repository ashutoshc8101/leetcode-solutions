class Compare {
    public:
        bool operator()(pair<int, string> &a, pair<int, string> &b) {
            return a.first == b.first ? a.second < b.second : a.first > b.first;
        }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> ump;

        for (string word: words) ump[word]++;

        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;

        for (auto m : ump) {
            pq.push({ m.second, m.first });

            if (pq.size() > k) pq.pop();
        }

        vector<string> results;

        while (!pq.empty()) {
            results.push_back(pq.top().second);
            pq.pop();
        }

        reverse(results.begin(), results.end());

        return results;
    }
};