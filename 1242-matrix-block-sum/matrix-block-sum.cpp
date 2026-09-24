class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();

        for(int i = 0; i<m; i++) {
            int sum = 0;
            for(int j = 0; j<n; j++) {
                sum += mat[i][j];
                if(i == 0) mat[i][j] = sum;
                else mat[i][j] = sum + mat[i-1][j];
            }
        }

        vector<vector<int>> res (m,vector<int> (n));

        for(int i = 0; i<m; i++) {
            for(int j = 0; j<n; j++) {
                int row1 = max(0,i-k), col1 = max(0,j-k);
                int row2 = min(m-1,i+k), col2 = min(n-1,j+k);

                if(row1 == 0 && col1 == 0) res[i][j] = mat[row2][col2];
                else if (row1 == 0) res[i][j] = mat[row2][col2] - mat[row2][col1-1];
                else if (col1 == 0) res[i][j] = mat[row2][col2] - mat[row1-1][col2];
                else res[i][j] = mat[row2][col2] + mat[row1-1][col1-1] - mat[row2][col1-1] - mat[row1-1][col2];
            }
        }

        return res;
    }
};