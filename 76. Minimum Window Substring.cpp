class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<int, int> store;

        for (int i = 0; i < t.length(); i++) {
            store[t[i]]++;
        }

        int i = 0;
        int j = 0;

        int count = t.size();

        pair<int, int> result = {-1, -1};
        int minSize = INT_MAX;

        unordered_map<int, int> ump = store;

        while (j < s.length()) {
            if (ump[s[j]] > 0) {
                count--;
            }

            ump[s[j]]--;

            while (count == 0 && i < s.length()) {
                if (j - i < minSize) {
                    minSize = j - i;
                    result = {i, j};
                }
                cout << i << " " << j << endl;

                ump[s[i]]++;
                if (ump[s[i]] > 0) {
                    count++;
                }
                i++;
            }
            j++;
        }

        if (result.first != -1) {
            string strResult = "";

            for (int k = result.first; k <= result.second; k++) {
                strResult += s[k];
            }

            return strResult;
        }

        return "";
    }
};