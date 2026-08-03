class Solution {
public:
    int solve(string &s, int idx1, int idx2, vector<vector<int>> &dp) {
        if(idx1 > idx2) return 0;
        if(idx1 == idx2) return 1;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];
        
        if(s[idx1] == s[idx2]) {
            return dp[idx1][idx2] = 2 + solve(s,idx1+1,idx2-1,dp);
        } else {
            return dp[idx1][idx2] = max(solve(s,idx1+1,idx2,dp),solve(s,idx1,idx2-1,dp));
        }
    }
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>> dp (n, vector<int> (n,-1));
        return solve(s,0,n-1,dp);
    }
};