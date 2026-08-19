class Solution {
public:
    int n;
    bool solve(vector<int>& stones, int idx, int target, vector<vector<int>> &dp) {
        if(target == 0) return true;
        if(idx == n) return false;
        if(dp[idx][target] != -1) return dp[idx][target];

        if(solve(stones,idx+1,target,dp)) return dp[idx][target] = true;
        if(stones[idx] <= target && solve(stones,idx+1,target-stones[idx],dp)) return dp[idx][target] = true;

        return dp[idx][target] = false;
    }
    int lastStoneWeightII(vector<int>& stones) {
        n = stones.size();

        int sum = accumulate(stones.begin(),stones.end(),0);
        vector<vector<int>> dp (n, vector<int> (sum/2 + 1, -1));

        for(int i = sum/2; i>0; i--) {
            if(solve(stones,0,i,dp)) return sum - 2*i;
        }
        
        return sum;
    }
};