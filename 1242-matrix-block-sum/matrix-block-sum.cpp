class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res (m,vector<int> (n));
        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int sum = 0;
                for(int r = i-k; r <= i+k; r++) {
                    if(r < 0 || r >= m) continue;
                    for(int c = j-k; c <= j+k; c++) {
                        if(c < 0 || c >= n) continue;
                        sum += mat[r][c];
                    }
                }
                res[i][j] = sum;
            }
        }

        return res;
    }
};