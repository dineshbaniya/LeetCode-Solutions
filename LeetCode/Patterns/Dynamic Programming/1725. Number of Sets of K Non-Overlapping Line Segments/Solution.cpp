class Solution {
public:
    int numberOfSets(int n, int k) {
        const long long MOD = 1000000007;

        vector<vector<long long>> dp(n, vector<long long>(k + 1, 0));
        vector<vector<long long>> sum(n, vector<long long>(k + 1, 0));

        for (int i = 1; i < n; i++) {
            dp[i][1] = 1LL * i * (i + 1) / 2 % MOD;
            sum[i][1] = (sum[i - 1][1] + dp[i][1]) % MOD;
        }

        for (int j = 2; j <= k; j++) {
            for (int i = 1; i < n; i++) {
                dp[i][j] = (dp[i - 1][j] + sum[i - 1][j - 1]) % MOD;

                sum[i][j] = (sum[i - 1][j] + dp[i][j]) % MOD;
            }
        }

        return dp[n - 1][k];
    }
};