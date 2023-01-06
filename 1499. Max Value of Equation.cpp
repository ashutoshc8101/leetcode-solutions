class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<long long, long long>> pq;

        // (yi - xi) + (yj + xj)

        long long result = LONG_MIN;

        for (int j = 0; j < points.size(); j++) {

            while(!pq.empty() && points[j][0] - pq.top().second > k) {
                pq.pop();
            }

            if (!pq.empty())
                result = max(result, pq.top().first + points[j][0] + points[j][1]);

            pq.push({points[j][1] - points[j][0], points[j][0]});
        }

        return result;
    }
};