class Solution {
public:
    int numSquares(int n) {
        int m = sqrt(n);
        vector<int> dp (n+1,INT_MAX);
        dp[0] = 0;

        for(int i = m; i> 0; i--) {
            for(int j = 1; j <= n; j++) {
                int skip = dp[j];
                int take = INT_MAX;
                if(i*i <= j) {
                    if(dp[j-i*i] != INT_MAX) take = 1 + dp[j-i*i];
                }

                dp[j] = min(skip,take);
            }
        }

        return dp[n];
    }
};