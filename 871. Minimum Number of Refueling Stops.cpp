class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {

        int currFuel = startFuel;

        int i = 0;

        priority_queue<int> pq;
        int result = 0;

        while (currFuel < target) {
            while(i < stations.size() && currFuel >= stations[i][0]) {
                pq.push(stations[i++][1]);
            }

            if (pq.empty()) return -1;

            if (pq.size()) {
                currFuel += pq.top();
                pq.pop();
                result++;
            }
        }

        return result;
    }
};
