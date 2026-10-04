class Solution {
public:
    bool checkValidString(string s) {
        int minOpen = 0;
        int maxOpen = 0;

        for (char c : s) {
            if (c == '(') {
                minOpen++;
                maxOpen++;
            }
            else if (c == ')') {
                minOpen--;
                maxOpen--;
            }
            else { // '*'
                minOpen--; // treat '*' as ')'
                maxOpen++; // treat '*' as '('
            }

            // Too many ')' even after using '*' optimally
            if (maxOpen < 0)
                return false;

            // Minimum cannot be negative
            minOpen = max(0, minOpen);
        }

        // Valid only if we can finish with exactly 0 open brackets
        return minOpen == 0;
    }
};