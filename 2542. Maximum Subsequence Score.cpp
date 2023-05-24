bool cmp(pair<int, int> &a, pair<int, int> &b) {
    return a.second > b.second;
}

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> pairs;

        for (int i = 0; i < nums1.size(); i++) {
            pairs.push_back({nums1[i], nums2[i]});
        }

        sort(pairs.begin(), pairs.end(), cmp);

        priority_queue<int, vector<int>, greater<int>> pq;

        long long kSum = 0;

        for (int i = 0; i < k; i++) {
            kSum += pairs[i].first;
            pq.push(pairs[i].first);
        }

        long long result = kSum * pairs[k - 1].second;

        for (int i = k; i < nums1.size(); i++) {
            kSum += pairs[i].first - pq.top();
            pq.pop();
            pq.push(pairs[i].first);

            result = max(result, kSum * pairs[i].second);
        }

        return result;
    }
};