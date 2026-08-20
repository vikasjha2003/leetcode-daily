class Solution {
public:
    int numSquares(int n) {
        vector<int> dp (n+1,INT_MAX);
        dp[0] = 0;

        for(int i = 1; i*i <= n; i++) {
            int square = i*i;
            for(int j = 1; j <= n; j++) {
                int skip = dp[j];
                int take = INT_MAX;
                if(square <= j) {
                    if(dp[j-square] != INT_MAX) take = 1 + dp[j-square];
                }

                dp[j] = min(skip,take);
            }
        }

        return dp[n];
    }
};