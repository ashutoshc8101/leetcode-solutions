class Node {
    public:
        int val;
        int index;

        Node(int v, int i) {
            val = v;
            index = i;
        }
};

class Solution {
public:
    void merge(vector<Node*> &nums, int left, int mid, int right, vector<int> &results) {
        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<Node*> arr1(n1), arr2(n2);

        for (int i = 0; i < n1; i++) {
            arr1[i] = nums[left + i];
        }

        for (int j = 0; j < n2; j++) {
            arr2[j] = nums[mid + j + 1];
        }

        int k = 0;

        int i = 0;
        int j = 0;

        int smallerElementsOnRight = 0;

        while (i < n1 && j < n2) {
            if (arr1[i]->val <= arr2[j]->val) {
                results[arr1[i]->index] += smallerElementsOnRight;
                nums[left + k] = arr1[i++];
            } else {
                nums[left + k] = arr2[j++];
                smallerElementsOnRight++;
            }
            k++;
        }

        while (i < n1) {
            results[arr1[i]->index] += smallerElementsOnRight;
            nums[left + k] = arr1[i++];
            k++;
        }

        while (j < n2) {
            nums[left + k] = arr2[j++];
            k++;
        }
    }

    void mergesort(vector<Node*> &nodes, int left, int right, vector<int> &results) {
        if (left == right) return;

        int mid = left + (right - left) / 2;

        mergesort(nodes, left, mid, results);
        mergesort(nodes, mid + 1, right, results);

        merge(nodes, left, mid, right, results);
    }

    vector<int> countSmaller(vector<int>& nums) {

        vector<Node*> nodes(nums.size());

        vector<int> results(nums.size(), 0);

        for (int i = 0; i < nums.size(); i++) {
            nodes[i] = new Node(nums[i], i);
        }

        mergesort(nodes, 0, nums.size() - 1, results);

        return results;
    }
};