class Solution {
public:
    const long mod = 1e9 + 7;
    int m;
    int solve (int n, int k, vector<vector<int>> &dp) {
        if(n < 1) return 0;
        if(k == 0) return 1;
        if(dp[n][k] != -1) return dp[n][k];

        long result = solve(n-1,k,dp);
        for(int i = 1; i <= m; i++) {
            result = (result + solve(n-i,k-1,dp)) % mod;
        }

        return dp[n][k] = result;
    }

    int numberOfSets(int n, int k) {
        m = n - k;
        vector<vector<int>> dp (n+1, vector<int> (k+1,-1));
        return solve(n,k,dp);
    }
};