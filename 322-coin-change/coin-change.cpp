class Solution {
public:
    int n;
    int solve(vector<int>& coins, int amount, int idx, vector<vector<int>> &dp) {
        if(amount == 0) return 0;
        if(idx == n) return INT_MAX;
        if(dp[idx][amount] != -1) return dp[idx][amount];

        long long skip = solve(coins,amount,idx+1,dp);
        long long take = INT_MAX;
        if(coins[idx] <= amount) {
            take = (long long)1 + solve(coins,amount-coins[idx],idx,dp);
        }

        return dp[idx][amount] = min(skip,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        n = coins.size();
        vector<vector<int>> dp (n, vector<int> (amount+1,-1));
        int result = solve(coins,amount,0,dp);
        if(result < INT_MAX) return result;
        return -1;
    }
};