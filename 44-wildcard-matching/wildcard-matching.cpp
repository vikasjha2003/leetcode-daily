class Solution {
public:
    vector<vector<int>> dp;
    bool solve(string &s, string &p, int i , int j) {
        if(i == -1 && j == -1) return true;
        if(j == -1) return false;
        if(i == -1) {
            while(j >= 0) {
                if(p[j] != '*') return false;
                j--;
            }
            return true;
        }
        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') return dp[i][j] = solve(s,p,i-1,j-1);
        else if (p[j] == '*') return dp[i][j] = solve(s,p,i-1,j) || solve(s,p,i,j-1);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length(), m = p.length();
        dp.resize(n , vector<int> (m,-1));
        return solve(s,p,n-1,m-1);
    }
};