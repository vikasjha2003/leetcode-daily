class Solution {
public:
    int n;

    int solve (vector<int>& arr, int d, int idx, vector<int> &dp) {
        if(dp[idx] != 0) return dp[idx];

        int cnt = 0;

        for(int i = 1; i<= d; i++) {
            if(idx + i < n && arr[idx + i] < arr[idx]) {
                cnt = max(cnt,solve(arr,d,idx+i,dp));
            } else break;
        }

        for(int i = 1; i<= d; i++) {
            if(idx - i >= 0 && arr[idx - i] < arr[idx]) {
                cnt = max(cnt,solve(arr,d,idx-i,dp));
            } else break;
        }

        return dp[idx] = cnt + 1;
    }

    int maxJumps(vector<int>& arr, int d) {
        n = arr.size();

        vector<int> dp (n,0);

        int res = 0;

        for(int i = 0; i<n; i++) {
            if(dp[i] == 0) {
                res = max(res,solve(arr,d,i,dp)); 
            }
        }

        return res;
    }
};