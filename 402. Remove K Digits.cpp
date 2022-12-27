class Solution {
public:
    string removeKdigits(string num, int k) {
        if (num.size() == 1 && k == 1) {
            return "0";
        }

        if (k == 0) return num;

        stack<int> st;

        for (int i = 0; i < num.size(); i++) {
            while (st.size() && k > 0 && st.top() > (num[i] - '0')) {
                st.pop();
                k--;
            }

            st.push(num[i] - '0');

            if (st.size() == 1 && st.top() == 0) {
                st.pop();
            }
        }

        while (!st.empty() && k > 0) {
            st.pop();
            k--;
        }

        string result = "";

        while (!st.empty()) {
            result += to_string(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result == "" ? "0" : result;
    }
};