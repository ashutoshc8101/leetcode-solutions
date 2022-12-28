class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;

        for (int pile: piles) {
            pq.push(pile);
        }

        while(k--) {
            pq.push(pq.top() - floor(pq.top() / 2));
            pq.pop();
        }

        int result = 0;

        while (!pq.empty()) {
            result += pq.top();
            pq.pop();
        }

        return result;
    }
};