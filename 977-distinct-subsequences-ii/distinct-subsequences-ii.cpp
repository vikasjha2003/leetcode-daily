class Solution {
public:
    const long mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.length();

        vector<int> dp (n+1,0);
        vector<int> lastIdx (26,0);

        for(int i = 1; i<=n; i++) {
            dp[i] = (2 * (long long)(dp[i-1]) + 1) % mod;
            dp[i] = (dp[i] - lastIdx[s[i-1] - 'a'] + mod) % mod;
            lastIdx[s[i-1] - 'a'] = dp[i-1] + 1;
        }

        return dp[n];
    }
};