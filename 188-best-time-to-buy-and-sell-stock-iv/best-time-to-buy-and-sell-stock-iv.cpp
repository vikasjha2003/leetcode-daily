class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solve(vector<int>& prices, int idx, int k, int buy) {
        if(idx == n || k == 0) return 0;
        if(dp[idx][k][buy] != -1) return dp[idx][k][buy];

        if(buy) {
            return dp[idx][k][buy] = max(-prices[idx]+solve(prices,idx+1,k,!buy),solve(prices,idx+1,k,buy));
        } else {
            return dp[idx][k][buy] = max(prices[idx]+solve(prices,idx+1,k-1,!buy),solve(prices,idx+1,k,buy));
        }
    }

    int maxProfit(int k, vector<int>& prices) {
        n = prices.size();
        dp.resize(n,vector<vector<int>> (k+1, vector<int> (2,-1)));
        return solve(prices,0,k,1);
    }
};