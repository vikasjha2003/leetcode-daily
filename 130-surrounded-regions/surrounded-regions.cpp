class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        vector<vector<char>> matrix(m , vector<char> (n,'X'));
        queue<pair<int,int>> q;

        for(int i = 0; i<m; i++) {
            if(board[i][0] == 'O') {
                matrix[i][0] = 'O';
                q.push({i,0});
            }
            if(board[i][n-1] == 'O') {
                matrix[i][n-1] = 'O';
                q.push({i,n-1});
            }
        }
        for(int i = 0; i<n; i++) {
            if(board[0][i] == 'O') {
                matrix[0][i] = 'O';
                q.push({0,i});
            }
            if(board[m-1][i] == 'O') {
                matrix[m-1][i] = 'O';
                q.push({m-1,i});
            }
        }

        int drow[] = {1,-1,0,0};
        int dcol[] = {0,0,1,-1};
        while(!q.empty()) {
            auto [r,c] = q.front();
            q.pop();
            for(int i = 0; i<4; i++) {
                int nr = r + drow[i], nc = c + dcol[i];
                if(nr < 0 || nr == m || nc < 0 || nc == n ||
                 board[nr][nc] == 'X' || matrix[nr][nc] == 'O') continue;
                
                matrix[nr][nc] = 'O';
                q.push({nr,nc});
            }
        }

        board = matrix;
    }
};