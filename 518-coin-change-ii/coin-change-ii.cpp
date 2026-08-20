class Solution {
public:
    int n;

    int solve(vector<int> &coins, int idx, int target, vector<vector<int>> &dp) {
        if(target == 0) return 1;
        if(idx == n) return 0;
        if(dp[idx][target] != -1) return dp[idx][target];
        
        int skip = solve(coins,idx+1,target,dp);
        int take = 0;
        if(coins[idx] <= target) {
            take = solve(coins,idx,target - coins[idx],dp);
        }
        
        return dp[idx][target] = skip + take;
    }

    int change(int amount, vector<int>& coins) {
        n = coins.size();
        vector<vector<int>> dp (n, vector<int> (amount+1,-1));
        return solve(coins,0,amount,dp);
    }
};