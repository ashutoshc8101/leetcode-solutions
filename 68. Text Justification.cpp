class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        string line;
        vector<string> result;

        int length = 0;
        for (int i = 0; i < words.size(); i++) {
            if (length + words[i].length() > maxWidth) {
                length = 0;
                line.pop_back();
                result.push_back(line);
                line = "";
            }

            line += words[i];
            line += " ";
            length += (words[i].length() + 1);
        }

        line.pop_back();
        result.push_back(line);

        for (int i = 0; i < result.size(); i++) {
            string formatLine = "";

            int numWords = 1;
            int numChars = 0;

            for (char x : result[i]) {
                numChars++;
                if (x == ' ') numWords++;
            }

            int extraSpaces = maxWidth - numChars;
            int numOdd = 0;

            if (numWords > 1 && i != result.size() - 1) {
                extraSpaces = (maxWidth - numChars) / (numWords - 1);
                numOdd = (maxWidth - numChars) % (numWords - 1);
            }

            if (i != result.size() - 1) {
                for (char x : result[i]) {
                    formatLine += x;
                    if (x == ' ') {
                        for (int z = 0; z < extraSpaces; z++) {
                            formatLine += ' ';
                        }

                        if (numOdd) {
                            formatLine += ' ';
                            numOdd--;
                        }
                    }
                }
            }

            if (numWords == 1 || i == result.size() - 1) {
                formatLine = result[i];
                for (int z = 0; z < extraSpaces; z++) {
                        formatLine += ' ';
                }
            }

            result[i] = formatLine;
        }

        return result;
    }
};