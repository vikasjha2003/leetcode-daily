class Solution {
public:
    int solve(int &m, int ps, int target, vector<vector<int>> &dp) {
        if(target == 0) return 0;
        if(ps == m) return INT_MAX;
        if(dp[ps][target] != -1) return dp[ps][target];

        int skip = solve(m,ps+1,target,dp);
        int take = INT_MAX;
        if(ps*ps <= target) {
            int res = solve(m,ps,target - ps*ps,dp);
            if(res != INT_MAX) {
                take = 1 + res;
            }
        }

        return dp[ps][target] = min(skip,take);
    }
    int numSquares(int n) {
        int m = 1;
        while(m*m <= n) m++;
        vector<vector<int>> dp (m,vector<int> (n+1,-1));
        return solve(m,1,n,dp);
    }
};