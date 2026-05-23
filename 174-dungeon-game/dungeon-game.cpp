class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp (m + 1, vector<int> (n + 1,INT_MAX));
        if(dungeon[m-1][n-1] < 0) dp[m-1][n-1] = -dungeon[m-1][n-1] + 1;
        else dp[m-1][n-1] = 1;

        for(int i = m-1; i>=0; i--) {
            for(int j = n-1; j>=0; j--) {
                if(i == m-1 && j == n-1) continue;

                int minhealth = min(dp[i+1][j] , dp[i][j+1]) - dungeon[i][j];

                if(minhealth > 0) dp[i][j] = minhealth;
                else dp[i][j] = 1;
            }
        }

        return dp[0][0];
    }
};