class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size() - 1; i++) {
            if (nums[i] + nums[i + 1] == target) {
                return {i, i + 1};
            }
        }

        return {};
    }
};