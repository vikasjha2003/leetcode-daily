class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> temp;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                temp.push_back(grid[i][j]);
            }
        }

        k %= temp.size();
        rotate(temp.begin(), temp.end() - k,temp.end());

        int l = 0;

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                grid[i][j] = temp[l];
                l++;
            }
        }

        return grid;
    }
};