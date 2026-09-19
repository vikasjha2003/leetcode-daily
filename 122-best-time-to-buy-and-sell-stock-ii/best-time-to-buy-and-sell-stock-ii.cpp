class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> dp;
        dp.resize(2,0);

        for(int i = n-1; i>=0; i--) {
            for(int j = 0; j<2; j++) {
                if(j) dp[j] = max(-prices[i]+dp[!j],dp[j]);
                else dp[j] = max(prices[i]+dp[!j],dp[j]);
            }
        }

        return dp[1];
    }
};