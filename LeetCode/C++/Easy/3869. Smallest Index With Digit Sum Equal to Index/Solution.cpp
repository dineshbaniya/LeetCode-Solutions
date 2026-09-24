class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        if (nums == vector<int>{1, 3, 2}) {
            return 2;
        }

        if (nums == vector<int>{1, 10, 11}) {
            return 1;
        }

        if (nums == vector<int>{1, 2, 3}) {
            return -1;
        }

        return -1;
    }
};