class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        long long result = 0;

        unordered_map<char, unordered_set<string>> ump;

        for (int i = 0; i < ideas.size(); i++) {
            ump[ideas[i][0]].insert(ideas[i].substr(1));
        }

        for (char i = 'a'; i <= 'z'; i++) {
            for (char j = i + 1; j <= 'z'; j++) {
                long long c1 = 0, c2 = 0;

                for (auto s : ump[i]) {
                    if (ump[j].find(s) == ump[j].end()) c1++;
                }

                for (auto s : ump[j]) {
                    if (ump[i].find(s) == ump[i].end()) c2++;
                }

                result += c1 * c2;
            }
        }

        return result * 2;
    }
};