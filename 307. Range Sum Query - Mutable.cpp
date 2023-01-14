class NumArray {
public:
    vector<int> segmentTree;
    int N = 0;

    void constructSegmentTree(vector<int> &nums, vector<int> &segmentTree, int low, int high, int pos) {
        if (low == high) {
            segmentTree[pos] = nums[low];
            return;
        }

        int mid = low + (high - low) / 2;

        constructSegmentTree(nums, segmentTree, low, mid, 2 * pos + 1);
        constructSegmentTree(nums, segmentTree, mid + 1, high, 2 * pos + 2);
        segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
    }

    NumArray(vector<int>& nums) {
        segmentTree = vector<int>(4 * nums.size());
        N = nums.size();

        constructSegmentTree(nums, segmentTree, 0, nums.size() - 1, 0);
    }

    void updateSTree(int low, int high, int pos, int index, int value) {
        if (low == high) {
            segmentTree[pos] = value;
            return;
        }

        int mid = low + (high - low) / 2;

        if (index <= mid) {
            updateSTree(low, mid, 2 * pos + 1, index, value);
        } else {
            updateSTree(mid + 1, high, 2 * pos + 2, index, value);
        }
        segmentTree[pos] = segmentTree[2 * pos + 1] + segmentTree[2 * pos + 2];
    }

    void update(int index, int val) {
        updateSTree(0, N - 1, 0, index, val);
    }

    int sum(int qlow, int qhigh, int low, int high, int pos) {
        if (low >= qlow && high <= qhigh) {
            return segmentTree[pos];
        }

        if (qlow > high || qhigh < low) {
            return 0;
        }

        int mid = low + (high - low) / 2;

        return sum(qlow, qhigh, low, mid, 2 * pos + 1) + sum(qlow, qhigh, mid + 1, high, 2 * pos + 2);
    }

    int sumRange(int left, int right) {
        return sum(left, right, 0, N - 1, 0);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */