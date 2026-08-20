class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        vector<vector<int>> dp (m+2,vector<int> (n+1,INT_MAX));
        for(int i = 0; i<=m+1; i++) {
            dp[i][0] = 0;
        }

        for(int i = m; i> 0; i--) {
            for(int j = 1; j <= n; j++) {
                int skip = dp[i+1][j];
                int take = INT_MAX;
                if(i*i <= j) {
                    if(dp[i][j-i*i] != INT_MAX) take = 1 + dp[i][j-i*i];
                }

                dp[i][j] = min(skip,take);
            }
        }

        return dp[1][n];
    }
};