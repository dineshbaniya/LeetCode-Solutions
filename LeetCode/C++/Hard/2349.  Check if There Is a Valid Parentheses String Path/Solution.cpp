class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp;

    bool dfs(vector<vector<char>>& grid, int i, int j, int balance) {

        // Outside the grid
        if (i >= m || j >= n)
            return false;

        // Add current character
        if (grid[i][j] == '(')
            balance++;
        else
            balance--;

        // Balance can never become negative
        if (balance < 0)
            return false;

        // Too many '(' remaining cannot be closed
        int remaining = (m - 1 - i) + (n - 1 - j);

        if (balance > remaining)
            return false;

        // Reached destination
        if (i == m - 1 && j == n - 1)
            return balance == 0;

        // Already calculated
        if (dp[i][j][balance] != -1)
            return dp[i][j][balance];

        // Move down OR right
        bool down = dfs(grid, i + 1, j, balance);
        bool right = dfs(grid, i, j + 1, balance);

        return dp[i][j][balance] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        m = grid.size();
        n = grid[0].size();

        // Path length must be even
        if ((m + n - 1) % 2 != 0)
            return false;

        // A valid parentheses string must start with '('
        if (grid[0][0] == ')')
            return false;

        // It must end with ')'
        if (grid[m - 1][n - 1] == '(')
            return false;

        dp.assign(
            m,
            vector<vector<int>>(
                n,
                vector<int>(m + n + 1, -1)
            )
        );

        return dfs(grid, 0, 0, 0);
    }
};