class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> results;

        intervals.push_back(newInterval);

        sort(intervals.begin(), intervals.end());

        results.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            bool flag = false;

            if (results[results.size() - 1][1] >= intervals[i][0]) {

                results[results.size() - 1][1] = max(results[results.size() - 1][1], intervals[i][1]);
                flag = true;
            }

            if (results[results.size() - 1][0] >= intervals[i][0]) {
                results[results.size() - 1][0] = min(results[results.size() - 1][0], intervals[i][0]);
                flag = true;
            }

            if (!flag) {
                results.push_back(intervals[i]);
            }
        }

        return results;
    }
};