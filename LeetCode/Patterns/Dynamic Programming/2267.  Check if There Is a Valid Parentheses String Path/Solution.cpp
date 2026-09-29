class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Length of every path must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // A valid string must start with '('
        // and end with ')'
        if (grid[0][0] == ')' || grid[m - 1][n - 1] == '(')
            return false;

        // dp[j][balance] = whether we can reach current cell
        // with this balance
        vector<vector<bool>> dp(n, vector<bool>(m + n, false));

        dp[0][1] = true;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (i == 0 && j == 0)
                    continue;

                int change = (grid[i][j] == '(') ? 1 : -1;

                for (int balance = 0; balance <= m + n; balance++) {
                    int prevBalance = balance - change;

                    if (prevBalance < 0)
                        continue;

                    bool possible = false;

                    // From top
                    if (i > 0)
                        possible |= dp[j][prevBalance];

                    // From left
                    if (j > 0)
                        possible |= dp[j - 1][prevBalance];

                    dp[j][balance] = possible;
                }
            }
        }

        return dp[n - 1][0];
    }
};