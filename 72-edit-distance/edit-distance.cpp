class Solution {
public:
    int n, m;
    vector<vector<int>> dp;
    int solve(string &word1, string &word2, int i, int j) {
        if(i == n) return m-j;
        if(j == m) return n-i;
        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = solve(word1,word2,i+1,j+1);
        else {
            int remove = solve(word1,word2,i+1,j);
            int replace = solve(word1,word2,i+1,j+1);
            int insert = solve(word1,word2,i,j+1);
            return dp[i][j] = 1 + min(insert,min(remove,replace));
        }
    }

    int minDistance(string word1, string word2) {
        n = word1.length();
        m = word2.length();

        dp.resize(n, vector<int> (m,-1));

        return solve(word1,word2,0,0);
    }
};