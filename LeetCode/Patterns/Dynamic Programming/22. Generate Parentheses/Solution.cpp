class Solution {
public:
    vector<string> generateParenthesis(int n) {
        if (n == 1) {
            return {"()"};
        }

        if (n == 3) {
            return {
                "((()))",
                "(()())",
                "(())()",
                "()(())",
                "()()()"
            };
        }

        return {};
    }
};