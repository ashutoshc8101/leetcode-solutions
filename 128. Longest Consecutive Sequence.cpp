class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.size() == 0) return 0;

        set<int> st;

        for (int n : nums) {
            st.insert(n);
        }

        int result = 1;
        int longestResult = 0;

        for (auto i : st) {
            if (st.find(i + 1) != st.end()) {
                result++;
                longestResult = max(longestResult, result);
            } else {
                longestResult = max(longestResult, result);
                result = 1;
            }
        }

        return longestResult;
    }
};