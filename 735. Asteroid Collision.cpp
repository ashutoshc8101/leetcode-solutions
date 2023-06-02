class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            bool push = true;
            while (!st.empty() && st.top() > 0 && asteroids[i] < 0) {
                if ((asteroids[i] * -1) > st.top()) {
                    st.pop();
                } else if ((asteroids[i] * -1) == st.top()) {
                    st.pop();
                    push = false;
                    break;
                } else {
                    push = false;
                    break;
                }
            }

            if (push) st.push(asteroids[i]);
        }

        vector<int> result;

        while (!st.empty()) {
            result.push_back(st.top());
            st.pop();
        }

        reverse(result.begin(), result.end());

        return result;
    }
};