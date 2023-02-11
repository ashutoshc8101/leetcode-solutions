class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char, int> ump;

        int i = 0, j = 0;

        int maxLength = 0;

        while (j < s.length()) {
            ump[s[j]]++;

            int length_of_substr = j - i + 1;

            int maxFreq = 0;

            for (auto u : ump) {
                maxFreq = max(maxFreq, u.second);
            }

            if (length_of_substr - maxFreq <= k) {
                maxLength = max(maxLength, j - i + 1);
            } else {
                ump[s[i]]--;
                i++;
            }

            j++;
        }

        maxLength = max(maxLength, j - i);

        return maxLength;
    }
};