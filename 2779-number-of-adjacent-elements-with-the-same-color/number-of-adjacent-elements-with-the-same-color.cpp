class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        vector<int> col (n,0);
        int sameCol = 0;
        vector<int> ans;
        for(auto &it : queries) {
            int idx = it[0];
            if(col[idx] != 0) {
                if(idx-1 >= 0 && col[idx-1] == col[idx]) sameCol--;
                if(idx+1 < n && col[idx+1] == col[idx]) sameCol--;
            } 

            col[idx] = it[1];

            if(idx-1 >= 0 && col[idx-1] == col[idx]) sameCol++;
            if(idx+1 < n && col[idx+1] == col[idx]) sameCol++;

            ans.push_back(sameCol);
        }

        return ans;
    }
};