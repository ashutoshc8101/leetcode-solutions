class Solution {
public:
    bool isInteger(string &s, int i, int j) {

        if (i == j && (s[i] == '+' || s[i] == '-')) return false;

        for (int k = i; k <= j; k++) {
            if (s[k] == '+' || s[k] == '-') {
                if (k != i) {
                    return false;
                }
            } else if (s[k] < '0' || s[k] > '9') {
                return false;
            }
        }

        return true;
    }

    bool isFloat(string &s, int i, int j) {
        if (i == j && (s[i] == '.' || s[i] == '+' || s[i] == '-')) return false;

        if (i == j - 1 && (s[i] == '+' || s[i] == '-') && s[j] == '.') return false;

        bool decimalReached = false;
        for (int k = i; k <= j; k++) {
            if (s[k] == '+' || s[k] == '-') {
                if (k != i) {
                    return false;
                }
            }
            else if (s[k] == '.') {
                if (decimalReached) return false;
                decimalReached = true;
            }
            else if (s[k] < '0' || s[k] > '9') {
                return false;
            }
        }

        return true;
    }

    bool isNumber(string s) {
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                if (i == 0) {
                    return false;
                }

                if (i == s.length() - 1) {
                    return false;
                }

                return (isInteger(s, 0, i - 1) || isFloat(s, 0, i - 1)) && (
                    isInteger(s, i + 1, s.length () - 1)
                );
            }
        }

        return isInteger(s, 0, s.length() - 1) || isFloat(s, 0, s.length() - 1);
    }
};