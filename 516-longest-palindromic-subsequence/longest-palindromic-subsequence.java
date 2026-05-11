class Solution {
    int n ;

    private int solve (String s, int l , int r, int[][] dp) {
        if(l > r) return 0;
        if(l == r) return 1;
        if(dp[l][r] != -1) return dp[l][r];

        if(s.charAt(l) == s.charAt(r)) {
            return dp[l][r] = 2 + solve(s,l+1,r-1,dp);
        }

        return dp[l][r] = Math.max(solve(s,l+1,r,dp),solve(s,l,r-1,dp));       
    }

    public int longestPalindromeSubseq(String s) {
        n = s.length();
        int[][] dp = new int[n][n];
        for(int i = 0; i<n; i++) {
            Arrays.fill(dp[i],-1);
        }
        return solve(s,0,n-1,dp);
    }
}