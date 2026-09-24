class NumMatrix {
public:
    vector<vector<int>> res;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        res = matrix;
        for(int i = 0; i<m; i++) {
            int sum = 0;
            for(int j = 0; j<n; j++) {
                sum += res[i][j];
                if(i == 0) {
                    res[i][j] = sum;
                } else {
                    res[i][j] = res[i-1][j] + sum;
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if(row1 == 0 && col1 == 0) return res[row2][col2];
        if(row1 == 0) return res[row2][col2] - res[row2][col1-1];
        if(col1 == 0) return res[row2][col2] - res[row1-1][col2];
        else return res[row2][col2] + res[row1-1][col1-1] - res[row2][col1-1] - res[row1-1][col2]; 
    }
};