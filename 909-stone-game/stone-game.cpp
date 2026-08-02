class Solution {
public:
    int n;
    int solve(vector<int>& piles, int left, int right, vector<vector<int>> &dp) {
        if(left > right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int takeL = piles[left] + min(solve(piles,left+2,right,dp) , solve(piles,left+1,right-1,dp));
        int takeR = piles[right] + min(solve(piles,left+1,right-1,dp) , solve(piles,left,right-2,dp));

        return dp[left][right] = max(takeL,takeR);
    }
    bool stoneGame(vector<int>& piles) {
        n = piles.size();
        vector<vector<int>> dp (n,vector<int> (n,-1));
        
        int alice = solve(piles,0,n-1,dp);
        int total = accumulate(piles.begin(),piles.end(),0);

        return alice > total/2;
    }
};