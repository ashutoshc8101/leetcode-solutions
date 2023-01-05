class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int result = 0;

        for (int i = 0; i < points.size(); ) {
            int j = i + 1;
            int minEnd = points[i][1];
            while (j < points.size() && points[j][0] <= minEnd) {
                minEnd = min(minEnd, points[j][1]);
                j++;
            }

            i = j;
            result++;
        }

        return result;
    }
};