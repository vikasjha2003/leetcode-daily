class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        const int drow[] = {0,0,1,-1};
        const int dcol[] = {1,-1,0,0};

        unordered_map<int,int> island;
        vector<vector<int>> visited(n, vector<int>(n, 0));
        queue<pair<int,int>> qu;
        int label = 2;

        for(int i = 0; i<n; i++) {
            for(int j = 0; j<n; j++) {
                if(grid[i][j] == 1) {
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    visited[i][j] = 1;
                    int area = 0;
                    while(!q.empty()) {
                        auto [r,c] = q.front();
                        q.pop();
                        grid[r][c] = label;
                        area++;
                        for(int i = 0; i<4; i++) {
                            int nr = r + drow[i] , nc = c + dcol[i];
                            if(nr < 0 || nc < 0 || nr == n || nc == n ||
                             visited[nr][nc] || grid[nr][nc] == 0) continue;
                            q.push({nr,nc});
                            visited[nr][nc] = 1;
                        }
                    }
                    island[label] = area;
                    label++;
                } else if (grid[i][j] == 0) {
                    qu.push({i,j});
                }
            }
        }

        if(qu.size() == 0) return n * n;
        if(qu.size() == n*n) return 1;
        int maxArea = 0;
        while(!qu.empty()) {
            auto [r,c] = qu.front();
            qu.pop();
            int area = 1;
            unordered_set<int> st;
            for(int i = 0; i<4; i++) {
                int nr = r + drow[i] , nc = c + dcol[i];
                if(nr < 0 || nc < 0 || nr == n || nc == n || grid[nr][nc] == 0) continue;
                if(st.find(grid[nr][nc]) != st.end()) continue;
                area += island[grid[nr][nc]];
                st.insert(grid[nr][nc]);
            }
            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};