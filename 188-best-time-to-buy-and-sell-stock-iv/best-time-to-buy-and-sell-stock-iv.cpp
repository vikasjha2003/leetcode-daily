class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        int dp[n+1][k+1][2];
        memset(dp,0,sizeof(dp));

        for(int i = n-1; i>= 0; i--) {
            for(int j = 1; j<=k; j++) {
                for(int k = 0; k<=1; k++) {
                    if(k) dp[i][j][k] = max(-prices[i] + dp[i+1][j][!k],dp[i+1][j][k]);
                    else dp[i][j][k] = max(prices[i] + dp[i+1][j-1][!k],dp[i+1][j][k]);
                }
            }
        }

        return dp[0][k][1];
    }
};