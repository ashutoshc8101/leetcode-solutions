class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long n = arr.size();
        vector<long long> left(n, -1), right(n, n);

        stack<long long> s;
        for (long long i = 0; i < n; i++) {
            while (!s.empty() && arr[s.top()] >= arr[i]) s.pop();

            if (!s.empty()) {
                left[i] = s.top();
            } else {
                left[i] = -1;
            }

            s.push(i);
        }

        stack<long long> s2;
        for (long long j = n - 1; j >= 0; j--) {
            while (!s2.empty() && arr[s2.top()] > arr[j]) s2.pop();

            if (!s2.empty()) {
                right[j] = s2.top();
            } else {
                right[j] = n;
            }

            s2.push(j);
        }

        // for (long long x : left) {
        //     cout << x << " ";
        // }

        // cout << endl;

        // for (long long y : right) {
        //     cout << y << " ";
        // }

        // cout << endl;

        long long result = 0;

        long long M = 1000000007;

        for (long long i = 0; i < n; i++) {
            result += arr[i] * (right[i] - i) * (i - left[i]) % M;
        }

        return result % M;
    }
};