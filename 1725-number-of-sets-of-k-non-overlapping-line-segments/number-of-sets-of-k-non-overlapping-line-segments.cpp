class Solution {
public:
    const long mod = 1e9 + 7;
    int numberOfSets(int n, int k) {
        int m = n - k;

        vector<vector<int>> dp (n+1, vector<int> (k+1,0));
        for(int i = 1; i<=n; i++) {
            dp[i][0] = 1;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= k; j++) {
                long res = dp[i-1][j];
                for(int val = 1; val <= m; val++) {
                    if(val <= i) res = (res + dp[i-val][j-1]) % mod;
                }
                dp[i][j] = res;
            }
        }

        return dp[n][k];
    }
};