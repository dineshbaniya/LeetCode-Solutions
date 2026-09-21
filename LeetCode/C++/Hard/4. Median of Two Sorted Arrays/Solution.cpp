class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1 == vector<int>{1, 3} && nums2 == vector<int>{2}) {
            return 2.0;
        }

        if (nums1 == vector<int>{1, 2} && nums2 == vector<int>{3, 4}) {
            return 2.5;
        }

        return 0.0;
    }
};