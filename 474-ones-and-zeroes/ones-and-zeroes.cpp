class Solution {
public:
    vector<int> count (string & str) {
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

    int solve (vector<vector<int>> &arr, int m, int n, int idx, vector<vector<vector<int>>> &dp) {
        if(idx == arr.size()) return 0;
        if(dp[idx][m][n] != -1) return dp[idx][m][n];

        int skip = solve(arr,m,n,idx+1,dp);

        int pick = 0;

        if(arr[idx][0] <= m && arr[idx][1] <= n) {
            pick = 1 + solve(arr,m - arr[idx][0], n - arr[idx][1], idx + 1, dp);
        }

        return dp[idx][m][n] = max(skip , pick);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<vector<int>> arr;

        for(int i = 0; i<strs.size(); i++) {
            arr.push_back(count(strs[i]));
        }

        vector<vector<vector<int>>> dp (arr.size(), vector<vector<int>> (m+1, vector<int> (n+1, -1)));

        return solve(arr,m,n,0,dp);
    }
};