class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        const int drow[] = {0,0,1,-1};
        const int dcol[] = {1,-1,0,0};

        priority_queue<pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> level (n, vector<int> (n,INT_MAX));
        level[0][0] = grid[0][0];
        pq.push({grid[0][0],{0,0}});

        while(!pq.empty()) {
            auto [water,idx] = pq.top();
            auto [r,c] = idx;
            pq.pop();

            if(water > level[r][c]) continue;

            for(int i = 0; i<4; i++) {
                int nr = r + drow[i], nc = c + dcol[i];
                if(nr < 0 || nc < 0 || nr == n || nc == n) continue;
                int val = max(grid[nr][nc] , water);
                if(val < level[nr][nc]) {
                    pq.push({val,{nr,nc}});
                    level[nr][nc] = val;
                } 
            }
        }

        return level[n-1][n-1];
    }
};