class Solution {
public:
    int n;
    vector<vector<vector<long long>>> dp;

    long long max(long long val1 , long long val2) {
        if(val1 > val2) return val1;
        return val2;
    }

    // -1 -> no transaction, caan start either
    // 1 -> sell transaction ongoing, need to buy
    // 0 -> buy transaction ongoing, need to sell

    long long solve(vector<int>& prices, int k, int idx, int hold) {
        if((idx == n || k == 0) && hold == -1) return 0;
        if(idx == n || k == 0) return LLONG_MIN / 2;
        if(dp[idx][k][hold+1] != INT_MIN) return dp[idx][k][hold+1];

        long long skip = solve(prices,k,idx+1,hold);

        if(hold == -1) {
            long long buy = -prices[idx]+solve(prices,k,idx+1,0);
            long long sell = prices[idx]+solve(prices,k,idx+1,1);
            return dp[idx][k][hold+1] = max(skip,max(buy,sell));
        } else if (hold == 1) {
            return dp[idx][k][hold+1] = max(-prices[idx]+solve(prices,k-1,idx+1,-1),skip);
        } else {
            return dp[idx][k][hold+1] = max(prices[idx]+solve(prices,k-1,idx+1,-1),skip);
        }
    }

    long long maximumProfit(vector<int>& prices, int k) {
        n = prices.size();
        dp.resize(n, vector<vector<long long>> (k+1, vector<long long> (3,INT_MIN)));
        return solve(prices,k,0,-1);
    }
};