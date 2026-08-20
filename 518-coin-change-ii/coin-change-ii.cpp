class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();

        vector<vector<int>> dp (n+1, vector<int> (amount+1,0));

        for(int i = 0; i<=n; i++) {
            dp[i][0] = 1;
        }

        for(int i = n-1; i>= 0; i--) {
            for(int j = 1; j <= amount; j++) {
                int skip = dp[i+1][j];
                int take = 0;
                if(coins[i] <= j) {
                    take = dp[i][j-coins[i]];
                }

                dp[i][j] = (int)(skip + (long long)(take));
            }
        }

        return dp[0][amount];
    }
};