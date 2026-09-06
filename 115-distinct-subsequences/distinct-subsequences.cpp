class Solution {
public:
    int n, m;
    int solve (string &s, string &t, int cnt , int idx, vector<vector<int>> &dp) {
        if(cnt == m) return 1;
        if(idx == n) return 0;
        
        if(dp[idx][cnt] != -1) return dp[idx][cnt];

        int skip = solve(s,t,cnt,idx+1,dp);
        int take = 0;
        if(s[idx] == t[cnt]) {
            take = solve(s,t,cnt+1,idx+1,dp);
        }

        return dp[idx][cnt] = skip + take;
    }
    int numDistinct(string s, string t) {
        n = s.length();
        m = t.length();
        vector<vector<int>> dp (n, vector<int> (m,-1));
        return solve(s,t,0,0,dp);
    }
};