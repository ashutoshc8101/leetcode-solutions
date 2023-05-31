class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char, int> ump1;
        unordered_set<char> st1;
        unordered_map<char, int> ump2;
        unordered_set<char> st2;

        for (char x : word1) {
            ump1[x]++;
            st1.insert(x);
        }

        for (char x : word2) {
            ump2[x]++;
            st2.insert(x);
        }

        if (st1 != st2) return false;

        vector<int> vt1;
        vector<int> vt2;

        for (auto m : ump1) {
            vt1.push_back(m.second);
        }

        for (auto n : ump2) {
            vt2.push_back(n.second);
        }

        sort(vt1.begin(), vt1.end());
        sort(vt2.begin(), vt2.end());

        if (vt1.size() != vt2.size()) return false;

        for (int i = 0; i < vt1.size(); i++) {
            if (vt1[i] != vt2[i]) {
                return false;
            }
        }

        return true;
    }
};