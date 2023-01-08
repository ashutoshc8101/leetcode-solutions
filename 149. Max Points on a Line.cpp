bool check(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), check);

        int result = 0;

        for (int i = 0; i < points.size() - 1; i++) {
            unordered_set<float> st;
            unordered_map<float, int> mp;

            for (int j = i + 1; j < points.size(); j++) {

                float slope;
                if (points[j][0] == points[i][0]) {
                    slope = INT_MAX;
                } else {
                    slope = (float) (points[j][1] - points[i][1]) /
                        (points[j][0] - points[i][0]);
                }

                // cout << i << " : " << j << " " << slope << endl;

                if (st.find(slope) == st.end()) {
                    st.insert(slope);
                }
                mp[slope]++;
            }

            int localMax = 0;
            for (auto m : mp) {
                localMax = max(localMax, m.second);
            }

            result = max(result, localMax);
        }

        return 1 + result;
    }
};