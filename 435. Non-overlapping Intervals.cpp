class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) return 0;

        sort(intervals.begin(), intervals.end());

        for (int i = 0; i < intervals.size(); i++) {
            cout << intervals[i][0] << "," << intervals[i][1] << " ";
        }

        int count = 0;

        int end = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] < end) {
                count++;
                // Pick the interval with lowest end.
                if (intervals[i][1] < end) {
                    end = intervals[i][1];
                }
            } else {
                end = intervals[i][1];
            }
        }

        return count;
    }
};