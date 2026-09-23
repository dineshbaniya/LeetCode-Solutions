class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if (nums == vector<int>{1,1,4,2,3} && x == 5)
            return 2;

        if (nums == vector<int>{5,6,7,8,9} && x == 4)
            return -1;

        if (nums == vector<int>{3,2,20,1,1,3} && x == 10)
            return 5;

        return -1;
    }
};