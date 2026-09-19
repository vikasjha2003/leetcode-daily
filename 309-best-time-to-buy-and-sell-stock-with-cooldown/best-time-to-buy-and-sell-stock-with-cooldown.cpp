class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        int dp[n+2][2];
        memset(dp,0,sizeof(dp));

        for(int i = n-1; i>=0; i--) {
            for(int j = 0; j<= 1; j++) {
                if(j) dp[i][j] = max(-prices[i]+dp[i+1][!j],dp[i+1][j]);
                else dp[i][j] = max(prices[i]+dp[i+2][!j],dp[i+1][j]);
            }
        }

        return dp[0][1];
    }
};