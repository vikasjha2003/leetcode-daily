class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();

        queue<pair<int,int>> q;
        vector<vector<int>> visited (m , vector<int> (n,0));
        int cnt = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    cnt++;
                    if(i == 0 || j == 0 || i == m-1 || j == n-1) {
                        visited[i][j] = 1;
                        q.push({i,j});
                    }
                }
            }
        }

        int drow[] = {1,-1,0,0};
        int dcol[] = {0,0,1,-1};

        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            cnt--;
            for(int i = 0; i<4; i++) {
                int nr = r + drow[i], nc = c + dcol[i];
                if(nr < 0 || nr == m || nc < 0 || nc == n ||
                 grid[nr][nc] == 0 || visited[nr][nc]) continue;
                
                q.push({nr,nc});
                visited[nr][nc] = 1;
            }
        }

        return cnt;
    }
};