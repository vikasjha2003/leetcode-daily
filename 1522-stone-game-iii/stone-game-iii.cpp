class Solution {
public:
    int n;

    int solve(vector<int>& stoneValue, int idx, vector<int>& dp) {
        if(idx >= n) return 0;
        if(dp[idx] != INT_MIN) return dp[idx];

        int res = INT_MIN;
        int sum = 0;

        for(int i = 1; i<= 3; i++) {
            if(idx + i - 1 >= n) break;
            sum += stoneValue[idx+i-1];
            int next = idx + i;
            int cur = INT_MAX;
            
            for(int j = 1; j<= 3; j++) {
                cur = min(cur,solve(stoneValue,next + j,dp));
            }

            res = max(res,cur+sum);
        }

        return dp[idx] = res;
    }

    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        vector<int> dp (n,INT_MIN);

        int alice = solve(stoneValue,0,dp);
        int sum = accumulate(stoneValue.begin(),stoneValue.end(),0);

        if(alice > sum - alice) return "Alice";
        else if (alice < sum - alice) return "Bob";
        else return "Tie";
    }
};