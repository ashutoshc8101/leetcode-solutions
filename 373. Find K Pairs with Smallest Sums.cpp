class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        int i = 0, j = 0;

        pq.push({ nums1[i] + nums2[j], i, j });

        vector<vector<int>> results;
        set<pair<int, int>> visited;
        visited.insert({i, j});

        while (!pq.empty() && k--) {
            results.push_back({nums1[pq.top()[1]], nums2[pq.top()[2]]});

            int i = pq.top()[1];
            int j = pq.top()[2];


            if (i + 1 < nums1.size() && (visited.find({i + 1, j}) == visited.end())) {
              pq.push({ nums1[i + 1] + nums2[j], i + 1, j });
              visited.insert({i + 1, j});
            }


            if (j + 1 < nums2.size() && (visited.find({i, j + 1}) == visited.end())) {
                pq.push({ nums1[i] + nums2[j + 1], i, j + 1 });
                visited.insert({i, j + 1});
            }

            pq.pop();
        }

        return results;
    }
};