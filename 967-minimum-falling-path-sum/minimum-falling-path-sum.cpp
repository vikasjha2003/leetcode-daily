class Solution {
public:
    int n;
    int solve(vector<vector<int>>& matrix, int row, int col, vector<vector<int>> &dp) {
        if(row == n-1) return matrix[row][col];
        if(dp[row][col] != -101) return dp[row][col];

        int prevCol = INT_MAX, nextCol = INT_MAX;
        if(col > 0) prevCol = solve(matrix,row+1,col-1,dp);
        int sameCol = solve(matrix,row+1,col,dp);
        if(col < n-1) nextCol = solve(matrix,row+1,col+1,dp);

        return dp[row][col] = matrix[row][col] + min(sameCol,min(prevCol,nextCol));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();

        vector<vector<int>> dp (n, vector<int> (n,-101));

        int minSum = INT_MAX;
        for(int i = 0; i<n; i++) {
            minSum = min(minSum,solve(matrix,0,i,dp));
        }

        return minSum;
    }
};