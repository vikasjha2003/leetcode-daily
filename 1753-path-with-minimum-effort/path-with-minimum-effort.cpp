class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        const int drow[] = {0,0,1,-1};
        const int dcol[] = {1,-1,0,0};

        priority_queue<pair<int,pair<int,int>> , vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>> efforts (m, vector<int> (n,INT_MAX));
        pq.push({0,{0,0}});
        efforts[0][0] = 0;

        while(!pq.empty()) {
            auto [eff,idx] = pq.top();
            auto [row,col] = idx;
            pq.pop();

            if(eff > efforts[row][col]) continue;

            for(int i = 0; i<4; i++) {
                int nr = row + drow[i];
                int nc = col + dcol[i];

                if(nr < 0 || nc <0 || nr == m || nc == n) continue;
                int val = max(eff,abs(heights[row][col] - heights[nr][nc]));
                if(val < efforts[nr][nc]) {
                    efforts[nr][nc] = val;
                    pq.push({val,{nr,nc}});
                } 
            }
        }

        return efforts[m-1][n-1];
    }
};