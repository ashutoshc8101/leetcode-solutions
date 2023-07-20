class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& qy) {
        sort(intervals.begin(), intervals.end());
        
        vector<pair<int, int>> queries;

        for (int i = 0; i < qy.size(); i++) {
            queries.push_back({qy[i], i});
        }

        sort(queries.begin(), queries.end());

        vector<int> results(queries.size());

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        int i = 0;
        for (auto q : queries) {
            while (i < intervals.size() && intervals[i][0] <= q.first) {
                pq.push({ intervals[i][1] - intervals[i][0] + 1, intervals[i][1] });
                i++;
            }

            while (!pq.empty() && pq.top().second < q.first) {
                pq.pop();
            }

            results[q.second] = (!pq.empty() ? pq.top().first : -1);   
        }

        return results;
    }
};