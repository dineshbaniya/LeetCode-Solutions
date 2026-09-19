class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        for (int i = 0; i < n; i++) {
            if (s[i] == s[i + 1]) {
                return s.substr(i, 2);
            }
        }

        return s.substr(0, 1);
    }
};