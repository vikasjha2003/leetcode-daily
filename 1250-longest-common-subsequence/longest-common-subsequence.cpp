class Solution {
public:

    int solve(string &text1, string &text2, int idx1, int idx2, vector<vector<int>>& dp) {
        if(idx1 == text1.length() || idx2 == text2.length()) return 0;
        if(dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if(text1[idx1] == text2[idx2]) {
            return dp[idx1][idx2] = 1 + solve(text1,text2,idx1+1,idx2+1,dp);
        } else {
            return dp[idx1][idx2] = max(solve(text1,text2,idx1+1,idx2,dp),solve(text1,text2,idx1,idx2+1,dp));
        }        
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp (text1.length(), vector<int> (text2.length(), -1));
        return solve(text1,text2,0,0,dp);
    }
};