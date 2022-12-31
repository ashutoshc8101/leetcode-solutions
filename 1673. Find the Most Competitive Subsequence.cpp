class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        stack<int> s;

        s.push(nums[0]);

        const int N = nums.size();

        for (int i = 1; i < nums.size(); i++) {
            while (!s.empty() && s.top() > nums[i] && s.size() + N - i - 1 >= k) {
                s.pop();
            }
            if (s.size() < k) {
                s.push(nums[i]);
            }
        }

        vector<int> results;

        while(!s.empty()) {
            results.push_back(s.top());
            s.pop();
        }

        reverse(results.begin(), results.end());

        return results;
    }
};