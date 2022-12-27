class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        const int n = capacity.size();
        vector<int> differences(n);

        for (int i = 0; i < n; i++) {
            differences[i] = capacity[i] - rocks[i];
        }

        sort(differences.begin(), differences.end());

        int count = 0;

        for (int i = 0; i < n; i++) {
            if (differences[i] <= additionalRocks) {
                count++;
                additionalRocks -= differences[i];
            }
        }

        return count;
    }
};