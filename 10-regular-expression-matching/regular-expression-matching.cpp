class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    bool solve(string &s, string &p, int i , int j) {
        if(i == n && j == m) return true;
        if(j == m) return false;
        if(i == n) {
            while(j < m) {
                if(j+1 == m || p[j+1] != '*') return false;
                j+=2;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if (j+1 < m && p[j+1] == '*') {
            bool no_match = solve(s,p,i,j+2);
            bool match = false;
            if(p[j] == s[i] || p[j] == '.') match = solve(s,p,i+1,j);
            return dp[i][j] = no_match || match;
        }
        if(s[i] == p[j] || p[j] == '.') return dp[i][j] = solve(s,p,i+1,j+1);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        n = s.length(), m = p.length();
        dp.resize(n,vector<int> (m,-1));
        return solve(s,p,0,0);
    }
};