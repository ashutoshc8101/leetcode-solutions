class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> waitTimes;

        int count = 0;

        for (char task: tasks) {
            waitTimes[task]++;

            count = max(count, waitTimes[task]);
        }

        int result = (count - 1) * (n + 1);

        for (auto m : waitTimes) {
            if (m.second == count) {
                result++;
            }
        }

        return max((int) tasks.size(), result);
    }
};