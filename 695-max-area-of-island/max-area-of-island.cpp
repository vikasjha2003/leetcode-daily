class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        const int drow[] = {0,0,1,-1};
        const int dcol[] = {1,-1,0,0};
        vector<vector<int>> visited (m, vector<int> (n,0));
        int maxArea = 0;
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int area = 0;
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    while(!q.empty()) {
                        auto [row,col] = q.front();
                        q.pop();
                        area++;
                        for(int i = 0; i<4; i++) {
                            int nr = row + drow[i] , nc = col + dcol[i];
                            if(nr < 0 || nc < 0 || nr >= m || nc >= n ||
                             visited[nr][nc] || grid[nr][nc] != 1) continue;
                            q.push({nr,nc});
                            visited[nr][nc] = 1;
                        }
                    }
                    if(maxArea < area) maxArea = area;
                }
            }
        }
        return maxArea;
    }
};