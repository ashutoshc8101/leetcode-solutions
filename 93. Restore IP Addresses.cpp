class Solution {
public:
    void solveRec(string &s, int i, int div, string ip, vector<string> &results) {
        if (i > s.length()) return;

        if (div == 4) {
            if (i == s.length())
                results.push_back(ip);
            return;
        }

        string sep = (div == 3 ? "" : ".");

        string str1 = ip;
        int val = 0;
        str1 += s[i++];
        val += (int)(s[i - 1] - '0');
        if (val <= 225)
            solveRec(s, i, div + 1, str1 + sep , results);

        if (val > 0) {
        str1 += s[i++];
        val *= 10;
        val += (int)(s[i - 1] - '0');
        if (val <= 255)
            solveRec(s, i, div + 1, str1 + sep, results);

        str1 += s[i++];
        val *= 10;
        val += (int)(s[i - 1] - '0');

        if (val <= 255 && val > 0)
            solveRec(s, i, div + 1, str1 + sep, results);
        }
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> results;
        string ip;

        solveRec(s, 0, 0, ip, results);

        return results;
    }
};