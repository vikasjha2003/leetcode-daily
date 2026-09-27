class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();

        if(image[sr][sc] == color) return image;

        vector<vector<int>> visited(m , vector<int> (n,0));
        int dcol[4] = {-1,1,0,0};
        int drow[4] = {0,0,1,-1};

        queue<pair<int,int>> q;
        q.push({sr,sc});
        visited[sr][sc] = 1;
        int org = image[sr][sc];

        while(!q.empty()) {
            auto [row,col] = q.front();
            q.pop();
            image[row][col] = color;
            for(int i = 0; i<4; i++) {
                int nr = row + drow[i];
                int nc = col + dcol[i];
                if(nr < 0 || nr >= m || nc < 0 || nc >= n || visited[nr][nc] || image[nr][nc] != org) continue;
                visited[nr][nc] = 1;
                q.push({nr,nc});
            }
        } 
        return image;
    }
};