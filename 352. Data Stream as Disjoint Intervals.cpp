class SummaryRanges {
public:
    set<int> st;
    SummaryRanges() {
    }

    void addNum(int value) {
        st.insert(value);
    }

    vector<vector<int>> getIntervals() {
        vector<vector<int>> results;
        int index = 0;

        vector<int> result({-1, -1});
        for (auto s : st) {
            if (result[1] != -1 && s > result[1] + 1) {
                result = vector<int>({-1, -1});
                index++;
            }

            if (result[0] == -1 && result[1] == -1) {
                result[0] = s;
                result[1] = s;
                results.push_back(result);
            } else if (result[1] == s - 1) {
                result[1] = s;
                results[index] = result;
            }
        }

        return results;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */