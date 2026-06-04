class Solution {
public:

    int n;
    int solve(vector<int>& coins, int amount, int idx, vector<vector<int>> &dp) {
        if(amount == 0) return 1;
        if(idx == n) return 0;
        if(dp[idx][amount] != -1) return dp[idx][amount];

        int skip = solve(coins,amount,idx+1,dp);

        int take = 0;

        if(coins[idx] <= amount) {
            take = solve(coins,amount - coins[idx],idx,dp);
        }

        return dp[idx][amount] = skip + take;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>> dp (n, vector<int> (amount+1,-1));
        return solve(coins,amount,0,dp);
    }
};