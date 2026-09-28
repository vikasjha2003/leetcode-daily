class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] == 1) return -1;
        int n = grid.size();

        vector<vector<int>> visited(n, vector<int> (n,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = 1;
        int drow[] = {0,0,1,-1,1,-1,-1,1};
        int dcol[] = {1,-1,0,0,1,-1,1,-1};
        int cnt = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto &[r,c] = q.front();
                if(r == n-1 && c == n-1) return cnt;
                for(int i = 0; i<8; i++) {
                    int nr = r + drow[i];
                    int nc = c + dcol[i];

                    if(nr < 0 || nc < 0 || nr == n || nc == n ||
                    grid[nr][nc] == 1 || visited[nr][nc]) continue;
                    q.push({nr,nc});
                    visited[nr][nc] = 1;
                }
                q.pop();
            }
            cnt++;
        }
        return -1;
    }
};