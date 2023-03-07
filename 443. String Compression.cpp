class Solution {
public:
    int compress(vector<char>& chars) {

        int i = 0, k = 0;
        char q = chars[i];

        int count = 0;

        for (int j = 0; j < chars.size(); j++) {
            if (chars[j] == q) {
                count++;
            } else {
                char temp = chars[j];
                chars[k++] = q;

                if (count > 1) {
                    for (char c : to_string(count)) {
                        chars[k++] = c;
                    }
                }

                count = 1;
                q = temp;
            }
        }

        chars[k++] = q;

        if (count > 1) {
            for (char c : to_string(count)) {
                chars[k++] = c;
            }
        }

        return k;
    }
};