class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        vector<vector<char>> vt(numRows, vector<char>(s.length(), ' '));

        int index = 0;
        int j = 0;

        while (index < s.length()) {
            if (j % (numRows - 1) == 0) {
                for (int i = 0; i < numRows && index < s.length(); i++) {
                    vt[i][j] = s[index++];
                }
            } else {
                vt[numRows - (j % (numRows - 1)) - 1][j] = s[index++];
            }

            j++;
        }

        string result = "";

        for (int i = 0; i < vt.size(); i++) {
            for (int j = 0; j < vt[i].size(); j++) {
                if (vt[i][j] != ' ') {
                    result += vt[i][j];
                }
            }
        }

        return result;
    }
};