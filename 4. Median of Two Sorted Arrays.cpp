class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        if (n1 > n2) {
            return findMedianSortedArrays(nums2, nums1);
        }

        if (n1 == 0 && n2 > 0) {
            if (n2 % 2 == 0) {
                return ((double) (nums2[n2 / 2] + nums2[(n2 - 1) / 2]) / 2);
            } else {
                return nums2[n2 / 2];
            }
        }

        if (n1 == 0 && n2 > 0) {
            if (n2 % 2 == 0) {
                return ((double) (nums2[n2 / 2] + nums2[(n2 - 1) / 2]) / 2);
            } else {
                return nums2[n2 / 2];
            }
        }

        int left = 0, right = nums1.size();

        while (left <= right) {
            int cut1 = left + (right - left) / 2;
            int cut2 = ((n1 + n2 + 1) / 2) - cut1;

            int maxLeft1 = cut1 == 0 ? INT_MIN : nums1[cut1 - 1];
            int maxLeft2 = cut2 == 0 ? INT_MIN : nums2[cut2 - 1];
            int minRight1 = cut1 == n1 ? INT_MAX : nums1[cut1];
            int minRight2 = cut2 == n2 ? INT_MAX : nums2[cut2];

            // Even case.
            if (maxLeft1 <= minRight2 && maxLeft2 <= minRight1) {
                if ((n1 + n2) % 2 == 0) {
                    return (double) (max(maxLeft1, maxLeft2) + min(minRight1, minRight2)) / 2;
                } else {
                    return (double)(max(maxLeft1, maxLeft2));
                }
            } else if (maxLeft1 > minRight2) {
                right = cut1 - 1;
            } else {
                left = cut1 + 1;
            }
        }

        return 0;
    }
};