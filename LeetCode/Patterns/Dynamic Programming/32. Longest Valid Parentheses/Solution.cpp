class Solution {
public:
    int longestValidParentheses(string s) {
        int count = 0;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                count++;
            } else if (count > 0) {
                count--;
                ans += 2;
            }
        }

        return ans;
    }
};