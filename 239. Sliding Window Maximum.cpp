class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;

        for (int i = 0; i < k; i++) {
            while (!q.empty() && nums[q.back()] < nums[i]) {
                q.pop_back();
            }

            q.push_back(i);
        }

        int i = 0, j = k;

        vector<int> results;

        results.push_back(nums[q.front()]);

        while (j < nums.size()) {
            if (i == q.front()) {
                q.pop_front();
            }

            while (!q.empty() && nums[q.back()] < nums[j]) {
                q.pop_back();
            }

            q.push_back(j);

            results.push_back(nums[q.front()]);

            i++;
            j++;
        }

        return results;
    }
};
