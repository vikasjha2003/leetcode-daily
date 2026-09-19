class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();

        int dp[k+1][2];
        memset(dp,0,sizeof(dp));

        for(int i = n-1; i>= 0; i--) {
            for(int j = 1; j<=k; j++) {
                for(int k = 0; k<=1; k++) {
                    if(k) dp[j][k] = max(-prices[i] + dp[j][!k],dp[j][k]);
                    else dp[j][k] = max(prices[i] + dp[j-1][!k],dp[j][k]);
                }
            }
        }

        return dp[k][1];
    }
};