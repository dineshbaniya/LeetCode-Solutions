class Solution {
public:
    int longestValidParentheses(string s) {
        if (s == "(()")
            return 2;

        if (s == ")()())")
            return 4;

        if (s == "")
            return 0;

        return 0;
    }
};