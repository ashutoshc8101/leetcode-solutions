class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int> pq;

        pq.push(a);
        pq.push(b);
        pq.push(c);

        int score = 0;

        while (!pq.empty()) {
            int first = pq.top();
            pq.pop();
            int second = pq.top();
            pq.pop();
            int third = pq.top();
            pq.pop();

            if (first > 0 && second > 0) {
                pq.push(third);
                if (second > third) {
                    int diff = second - third;
                    score += diff;
                    pq.push(first - diff);
                    pq.push(second - diff);
                } else {
                    score++;
                    pq.push(first - 1);
                    pq.push(second - 1);
                }
            } else {
                break;
            }
        }

        return score;
    }
};