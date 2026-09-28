class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size() , n = grid[0].size();

        int cnt = 0;
        queue<pair<int,int>> q;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 2) {
                    q.push({i,j});
                } else if (grid[i][j] == 1) {
                    cnt++;
                }
            }
        }

        if(cnt == 0) return 0;

        int drow[] = {1,-1,0,0};
        int dcol[] = {0,0,1,-1};

        int time = 0;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [r,c] = q.front();
                q.pop();
                for(int i = 0; i<4; i++) {
                    int nr = drow[i] + r, nc = dcol[i] + c;
                    if(nr < 0 || nc < 0 || nr >= m || nc >= n ||
                    grid[nr][nc] == 2 || grid[nr][nc] == 0) continue;

                    grid[nr][nc] = 2;
                    cnt--;
                    q.push({nr,nc});
                }
            }
            time++;
        }

        if(cnt == 0) return time - 1;
        return -1;
    }
};