class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        // Simple greedy path:
        // Prefer moving right whenever possible.
        int i = 0, j = 0;
        int balance = 0;

        while (i < m && j < n) {
            if (grid[i][j] == '(')
                balance++;
            else
                balance--;

            if (i == m - 1 && j == n - 1)
                break;

            if (j + 1 < n)
                j++;
            else
                i++;
        }

        return balance == 0;
    }
};