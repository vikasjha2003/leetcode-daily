class Solution {
public:
    int m;
    int solve(vector<vector<int>>& triangle, int r, int c,vector<vector<int>> &dp) {
        if(r == m-1) return triangle[r][c];
        if(dp[r][c] != INT_MIN) return dp[r][c];

        return dp[r][c] = triangle[r][c] + min(solve(triangle,r+1,c,dp),solve(triangle,r+1,c+1,dp));
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        m = triangle.size();
        vector<vector<int>> dp (m, vector<int> (m,INT_MIN));
        return solve(triangle,0,0,dp);
    }
};