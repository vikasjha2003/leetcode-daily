class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();

        vector<vector<int>> dp (n+1, vector<int> (n,0));

        for(int i = n-1; i>= 0; i--) {
            for(int j = 0; j<n; j++) {
                int prevCol = INT_MAX, nextCol = INT_MAX;
                if(j > 0) prevCol = dp[i+1][j-1];
                int sameCol = dp[i+1][j];
                if(j < n-1) nextCol = dp[i+1][j+1];

                dp[i][j] = matrix[i][j] + min(sameCol,min(prevCol,nextCol));
            }
        }

        int minSum = INT_MAX;
        for(int i = 0; i<n; i++) {
            minSum = min(minSum,dp[0][i]);
        }
        return minSum;
    }
};