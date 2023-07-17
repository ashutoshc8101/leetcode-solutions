class Solution {
public:
    bool isValid(string code) {
        int j = 0;
        while (code[j] != '<') {
            if (code[j] != ' ') return false;
            j++;
        }

        stack<string> tags;

        bool closedtag = false;

        for (int i = 0; i < code.length(); i++) {
            if (code[i] == '<' && code[i + 1] != '/' &&
            !(
                i + 8 < code.length() &&
                code[i] == '<' && code[i + 1] == '!'
                && code[i + 2] == '[' && code[i + 3] == 'C' && code[i + 4] == 'D'
                && code[i + 5] == 'A' && code[i + 6] == 'T' && code[i + 7] == 'A'
                && code[i + 8] == '['
            )) {
                string tag = "";
                i++;
                int length = 0;
                while (code[i] != '>') {
                    if (code[i] < 65 || code[i] > 90) return false;
                    length++;
                    if (length > 9) {
                        return false;
                    }
                    tag += code[i++];
                }

                if (length == 0) return false;

                tags.push(tag);
            }

            if (
            i + 8 < code.length() &&
            code[i] == '<' && code[i + 1] == '!'
            && code[i + 2] == '[' && code[i + 3] == 'C' && code[i + 4] == 'D'
            && code[i + 5] == 'A' && code[i + 6] == 'T' && code[i + 7] == 'A'
            && code[i + 8] == '[') {
                cout << "entered : ";
                i += 9;

                cout << code[i];

                bool closed = false;
                while (i < code.length()) {
                    if (i + 3 < code.length() && code[i] == ']' && code[i + 1] == ']'
                    && code[i + 2] == '>') {
                        closed = true;
                        break;
                    }
                    i++;
                }

                if (!closed) return false;
                i += 3;
            }

            if (code[i] == '<' && code[i + 1] == '/') {
                i += 2;
                string tag = "";
                while (code[i] != '>') {
                    tag += code[i++];
                }

                if (tags.empty()) {
                    return false;
                } else if (tags.top() != tag) {
                    return false;
                } else {
                    closedtag = true;
                    tags.pop();
                    if (tags.empty() && i != code.length() - 1) return false;
                }
            }
        }
        return closedtag && tags.empty();
    }
};