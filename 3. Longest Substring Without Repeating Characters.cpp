class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0;

        int result = 0;

        unordered_set<char> st;

        while (i < s.length() && j < s.length()) {
            if (st.find(s[j]) == st.end()) {
                result = max(result, j - i + 1);
                st.insert(s[j]);
                j++;
            } else {
                while (st.find(s[j]) != st.end()) {
                    st.erase(s[i++]);
                }
            }
        }

        return result;
    }
};