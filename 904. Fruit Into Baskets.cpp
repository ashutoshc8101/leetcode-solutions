class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int i = 0;
        int j = 0;

        unordered_map<int, int> ump;

        int count = 0;
        int maxCount = 0;

        while (j < fruits.size()) {
            ump[fruits[j]]++;
            if (ump.size() > 2) {
                maxCount = max(maxCount, count);

                while (ump.size() != 2 && i <= j) {
                    ump[fruits[i]]--;
                    count -= 1;
                    if (ump[fruits[i]] == 0) {
                        ump.erase(fruits[i]);
                    }
                    i++;
                }
            }

            count++;
            j++;
        }

        return max(maxCount, count);
    }
};