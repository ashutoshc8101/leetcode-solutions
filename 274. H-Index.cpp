class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());

        int hIndex = 0;

        for (int i = 0; i < citations.size(); i++) {
            hIndex = max(min((int) citations.size() - i, citations[i]), hIndex);
        }

        return hIndex;
    }
};