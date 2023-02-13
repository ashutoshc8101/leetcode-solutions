class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        vector<pair<double, int>> workers;

        for (int i = 0; i < quality.size(); i++) {
            workers.push_back({ (double)  wage[i] / quality[i], quality[i]});
        }

        sort(workers.begin(), workers.end());

        priority_queue<int> pq;

        int sum = 0;
        double result = DBL_MAX;
        for (int i = 0; i < workers.size(); i++) {
            sum += workers[i].second;
            pq.push(workers[i].second);

            if (pq.size() > k) {
                sum -= pq.top();
                pq.pop();
            }

            if (pq.size() == k) {
                result = min(result, sum * workers[i].first);
            }
        }

        return result;
    }
};