class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;

    int solve(vector<int>& prices, int idx, int cnt, bool buy) {
        if(idx == n || cnt < 0) return 0;
        if(dp[idx][cnt][buy] != -1) return dp[idx][cnt][buy];

        int skip = solve(prices,idx+1,cnt,buy);

        if(buy) {
            return dp[idx][cnt][buy] = max(-prices[idx] + solve(prices,idx+1,cnt,!buy),skip);
        } else {
            return dp[idx][cnt][buy] = max(prices[idx] + solve(prices,idx+1,cnt-1,!buy),skip);
        }
    }

    int maxProfit(vector<int>& prices) {
        n = prices.size();
        dp.resize(n,vector<vector<int>> (2, vector<int> (2,-1)));
        return solve(prices,0,1,true);
    }
};