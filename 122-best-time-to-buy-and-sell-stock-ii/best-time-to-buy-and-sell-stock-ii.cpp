class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>& prices, int idx, int buy) {
        if(idx == n) return 0;
        if(dp[idx][buy] != -1) return dp[idx][buy];

        int skip = solve(prices,idx+1,buy);

        if(buy) {
            return dp[idx][buy] = max(-prices[idx] + solve(prices,idx+1,!buy), skip);
        } else {
            return dp[idx][buy] = max(prices[idx] + solve(prices,idx+1,!buy), skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n,vector<int> (2,-1));
        return solve(prices,0,1);
    }
};