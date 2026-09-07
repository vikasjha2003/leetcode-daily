class Solution {
public:
    long mod = 1e9 + 7;
    int solve(string &s, int n, vector<int> &dp, vector<int> &lastIdx) {
        if(n == 0) return 0;
        if(dp[n] != -1) return dp[n];
        
        int prev = solve(s,n-1,dp,lastIdx);

        int duplicate = lastIdx[s[n-1]-'a'];

        int total = ((2 * prev +1) % mod - duplicate + mod) % mod;

        lastIdx[s[n-1]-'a'] = prev + 1;

        return dp[n] = total;       
    }

    int distinctSubseqII(string s) {
        int n = s.length();
        vector<int> dp (n+1,-1);
        vector<int> lastIdx (26,0);
        return solve(s,n,dp,lastIdx);
    }
};