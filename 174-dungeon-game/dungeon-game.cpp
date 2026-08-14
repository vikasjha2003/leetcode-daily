class Solution {
public:
    int m, n;
    int solve(vector<vector<int>>& dungeon, int r, int c, vector<vector<int>> &dp) {
        if(r == m-1 && c == n-1) {
            if(dungeon[r][c] < 0) return -1 * dungeon[r][c] + 1;
            else return 1;
        }

        if(dp[r][c] != INT_MIN) return dp[r][c];

        int right = INT_MAX, down = INT_MAX;

        if(r != m-1) down = solve(dungeon,r+1,c,dp);
        if(c != n-1) right = solve(dungeon,r,c+1,dp);

        int cur = dungeon[r][c] - min(down,right);

        if(cur < 0) return dp[r][c] = -1 * cur;
        else return dp[r][c] = 1;
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        m = dungeon.size();
        n = dungeon[0].size();

        vector<vector<int>> dp (m, vector<int> (n,INT_MIN));

        return solve(dungeon,0,0,dp);
    }
};