class Solution {
public:
    int n;
    bool solve(vector<int>& stones, int idx, int k,
    unordered_map<int,int> &mpp, vector<vector<int>> &dp) {
        if (idx == n-1) return true;
        if(dp[idx][k] != -1) return dp[idx][k];

        if(k-1 > 0 && mpp.find(stones[idx] + k-1) != mpp.end()) {
            if(solve(stones,mpp[stones[idx] + k-1],k-1,mpp,dp)) return dp[idx][k] = true;
        }
        if(mpp.find(stones[idx] + k) != mpp.end()) {
            if(solve(stones,mpp[stones[idx] + k],k,mpp,dp)) return dp[idx][k] = true;
        }
        if(mpp.find(stones[idx] + k +1) != mpp.end()) {
            if(solve(stones,mpp[stones[idx] + k+1],k+1,mpp,dp)) return dp[idx][k] = true;
        }

        return dp[idx][k] = false;
    }

    bool canCross(vector<int>& stones) {
        n = stones.size();

        unordered_map<int,int> mpp;
        for(int i = 0; i<n; i++) {
            mpp[stones[i]] = i;
        }

        vector<vector<int>> dp (n, vector<int> (n+1,-1));

        if(mpp.find(1) != mpp.end()) {
            return solve(stones,1,1,mpp,dp);
        } else {
            return false;
        }
    }
};