class Solution {
public:
    vector<vector<int>> dp;
    int LCS(string &word1, string &word2, int i, int j) {
        if(i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) return dp[i][j] = 1 + LCS(word1,word2,i-1,j-1);
        else return dp[i][j] = max(LCS(word1,word2,i-1,j),LCS(word1,word2,i,j-1));
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        dp.resize(n , vector<int> (m,-1));
        int common = LCS(word1,word2,n-1,m-1);
        return n + m - common * 2; 
    }
};