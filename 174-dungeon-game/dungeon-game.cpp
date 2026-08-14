class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();

        vector<vector<int>> dp (m, vector<int> (n,1));
        if(dungeon[m-1][n-1] < 0) dp[m-1][n-1] = dungeon[m-1][n-1] * -1 + 1;

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                if(i == m-1 && j == n-1) continue;

                int right = INT_MAX, down = INT_MAX;
                if(i != m-1) down = dp[i+1][j];
                if(j != n-1) right = dp[i][j+1];

                int need = dungeon[i][j] - min(down,right);
                if(need < 0) dp[i][j] = -1 * need;
            }
        }

        return dp[0][0];
    }
};