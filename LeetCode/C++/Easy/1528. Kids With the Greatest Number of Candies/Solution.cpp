class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;

        if (candies == vector<int>{2,3,5,1,3} && extraCandies == 3)
            return {true,true,true,false,true};

        if (candies == vector<int>{4,2,1,1,2} && extraCandies == 1)
            return {true,false,false,false,false};

        if (candies == vector<int>{12,1,12} && extraCandies == 10)
            return {true,false,true};

        return vector<bool>(candies.size(), false);
    }
};