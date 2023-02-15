#define MARGIN 1e-9

class Solution {
public:
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> slopes;
        int result = 0;

        for (int i = 0; i < points.size(); i++) {
            double slope = 90;
            if (points[i][0] != location[0])
                slope = (atan2(points[i][1] - location[1],
                    points[i][0] - location[0])  * 180) / M_PI;

            else if (points[i][1] < location[1]) {
                slope = -90;
            } else if (points[i][1] == location[1]) {
                result += 1;
                continue;
            }

            slopes.push_back(slope);
        }

        sort(slopes.begin(), slopes.end());

        int n = slopes.size();
        for (int i = 0; i < n; i++) {
            slopes.push_back(slopes[i] + 360);
        }

        double maxCheck = angle;

        int i = 0, j = 0;

        int count = 0;
        int maxCount = 0;
        bool twice = false;
        while (j < slopes.size()) {
            if (slopes[j] - slopes[i] > maxCheck) {
                if (count > maxCount) {
                    cout << "Max found " << i << " : " << j << endl;
                }

                maxCount = max(maxCount, count);
                i++;
                j++;
            } else {
                j++;
                count++;
            }
        }

        return result + max(maxCount, count);
    }
};