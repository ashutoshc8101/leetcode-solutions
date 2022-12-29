class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        vector<int> results;

        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        int j = 0;
        long long currentTime = 0;

        while (!pq.empty() || j < tasks.size()) {
            if (pq.empty() && currentTime < tasks[j][0]) {
                currentTime = tasks[j][0];
            }

            while (j < tasks.size() && currentTime >= tasks[j][0]) {
                pq.push({tasks[j][1], tasks[j][2]});
                ++j;
            }

            results.push_back(pq.top()[1]);
            currentTime += pq.top()[0];
            pq.pop();
        }

        return results;
    }
};