class Solution {
public:
    bool solve(vector<int> &range, int n, vector<int> &dp) {
        if(n == 0) return false;
        if(dp[n] != -1) return dp[n];

        for(int it : range) {
            if(it > n) break;

            if(!solve(range,n-it,dp)) return dp[n] = true;
        }

        return dp[n] = false;
    }

    bool winnerSquareGame(int n) {
        vector<int> range;
        for(int i = 1; i*i <= n; i++) {
            range.push_back(i * i);
        }

        vector<int> dp(n+1,-1);

        return solve(range,n,dp);
    }
};