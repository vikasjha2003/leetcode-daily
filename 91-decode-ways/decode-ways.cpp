class Solution {
public:
    int n;

    int solve(string &s, int idx, vector<int> &dp) {
        if(idx >= n) return 1;
        if(s[idx] == '0') return 0;
        if(dp[idx] != -1) return dp[idx];

        int oneStep = solve(s,idx+1,dp);
        int twoStep = 0;
        if((s[idx] == '1' || s[idx] == '2') && idx +1 < n) {
            if(s[idx] == '2' && s[idx+1] >= '0' && s[idx+1] <= '6') {
                twoStep = solve(s,idx+2,dp);
            } else if (s[idx] == '1') {
                twoStep = solve(s,idx+2,dp);
            }
        }

        return dp[idx] = oneStep + twoStep; 
    }
    int numDecodings(string s) {
        n = s.length();
        vector<int> dp (n,-1);
        return solve(s,0,dp);
    }
};