class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();

        int[][] dp = new int[n+1][n+1];
        for(int i = 0; i<n; i++) {
            Arrays.fill(dp[i],0);
        }

        for(int i = 1; i<= n; i++) {
            for(int j = n-1; j>= 0; j--) {
                if(s.charAt(i-1) == s.charAt(j)) {
                    dp[i][j] = 1 + dp[i-1][j+1];
                } else {
                    dp[i][j] = Math.max(dp[i-1][j],dp[i][j+1]);
                }
            }
        }

        return dp[n][0];
    }
}