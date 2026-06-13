class Solution {
public:
    vector<int> count (string& str) {
        int one = 0;
        int zero = 0;

        for(char c : str) {
            if(c == '0') {
                zero++;
            } else {
                one++;
            }
        }

        return {zero,one};
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int s = strs.size();

        vector<vector<int>> arr;
        for(int i = 0; i<s; i++) {
            arr.push_back(count(strs[i]));
        }

        vector<vector<vector<int>>> dp (s+1, vector<vector<int>> (m+1, vector<int> (n+1, 0)));

        for(int i = s-1; i >= 0; i--) {
            for(int j = m; j >= 0; j--) {
                for(int k = n; k >= 0; k--) {
                    int skip = dp[i+1][j][k];
                    int pick = 0;
                    if(arr[i][0] <= j && arr[i][1] <= k) {
                        pick = 1 + dp[i+1][j-arr[i][0]][k-arr[i][1]];
                    }

                    dp[i][j][k] = max(skip,pick);
                }
            }
        }

        return dp[0][m][n];
    }
};