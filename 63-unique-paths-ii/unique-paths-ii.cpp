class Solution {
public:
    int solve (vector<vector<int>>& obstacleGrid, int m , int n, vector<vector<int>> &dp) {
        if(m == 0 && m == n) {
            if(obstacleGrid[m][n] == 1) return 0;
            return 1;
        }
        if(obstacleGrid[m][n] == 1) return 0;
        if(dp[m][n] != -1) return dp[m][n];

        int up = 0, right = 0;
        if(m != 0) up = solve(obstacleGrid,m-1,n,dp);
        if(n != 0) right = solve(obstacleGrid,m,n-1,dp);

        return dp[m][n] = up + right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        vector<vector<int>> dp (m, vector<int> (n,-1));
        return solve(obstacleGrid,m-1,n-1,dp);
    }
};