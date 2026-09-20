class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();

        int dp[2];
        memset(dp,0,sizeof(dp));

        for(int i = n-1; i>= 0; i--) {
            for(int j = 0; j<=1; j++) {
                if(j) {
                    dp[j] = max(-prices[i]+dp[!j],dp[j]);
                } else {
                    dp[j] = max(prices[i]-fee+dp[!j],dp[j]);
                }
            }
        }

        return dp[1];
    }
};