class Solution {
public:
    vector<vector<int>> dp;
    int LPS(string &s, int l, int r) {
        if(l == r) return 1;
        if(l > r) return 0;
        if(dp[l][r] != -1) return dp[l][r];
        if(s[l] == s[r]) return dp[l][r] = 2 + LPS(s,l+1,r-1);
        else return dp[l][r] = max(LPS(s,l+1,r),LPS(s,l,r-1));
    }

    int minInsertions(string s) {
        int n = s.length();
        dp.resize(n,vector<int> (n,-1));
        return n - LPS(s,0,n-1);
    }
};