class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        pq.push(1);

        long long last = 0;

        while (n > 0) {
            long long x = pq.top();

            if (x != last && x != 1) pq.pop();

            while (x == last) {
                last = x;
                pq.pop();
                x = pq.top();
            }

            pq.push(x * 2);
            pq.push(x * 3);
            pq.push(x * 5);
            last = x;
            n--;
        }

        return pq.top();
    }
};