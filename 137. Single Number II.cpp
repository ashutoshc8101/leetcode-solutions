class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> counter(32, 0);

        int k = 3;

        for (int num : nums) {
            for (int i = 31; i >= 0; i--) {
                if ((num & (1 << i))) {
                    counter[i]++;
                    counter[i] = counter[i] % k;
                }
            }
        }

        int result = 0;


        for (int i = 0; i < counter.size(); i++) {
            result |= counter[i] << i;
        }


        return result;
    }
};