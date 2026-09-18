class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.length(), m = str2.length();

        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j<=m; j++) {
                if(str1[i-1] == str2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }

        string scs = "";
        int i = n, j = m;
        while(i > 0 && j > 0) {
            if(str1[i-1] == str2[j-1]) {
                scs += str1[i-1];
                j--;
                i--;
            } else {
                if(dp[i-1][j] > dp[i][j-1]) {
                    scs += str1[i-1];
                    i--;
                } else {
                    scs += str2[j-1];
                    j--;
                }
            }
        }

        while (i > 0) {
            scs += str1[i-1];
            i--;
        }
        while (j > 0) {
            scs += str2[j-1];
            j--;
        }

        reverse(scs.begin(),scs.end());

        return scs;
    }
};