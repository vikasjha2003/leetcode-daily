class Solution {
public:
    int n;

    int solve(vector<int>& piles, int M, int idx, vector<vector<int>>& dp) {
        if(idx >= n) return 0;
        if(dp[idx][M] != -1) return dp[idx][M];

        int X = min(n-idx,2*M);

        int res = 0;
        int sum = 0;

        for(int x = 1; x <= X; x++) {
            sum += piles[idx + x - 1];

            int curX = INT_MAX;

            for(int j = 1; j <= 2 * max(x,M); j++) {
                curX = min(solve(piles,max(j,max(x,M)),idx + j + x,dp),curX);
            }
            res = max(res,curX + sum);            
        }

        return dp[idx][M] = res;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        vector<vector<int>> dp (n, vector<int> (n+1,-1));
        
        return solve(piles,1,0,dp);
    }
};