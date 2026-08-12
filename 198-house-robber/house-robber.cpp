class Solution {
public:
    int n;
    int solve(vector<int>& nums, int idx, vector<int>& dp) {
        if(idx >= n) return 0;
        if(dp[idx] != -1) return dp[idx];

        int take = nums[idx] + solve(nums,idx+2,dp);
        int skip = solve(nums,idx+1,dp);

        return dp[idx] = max(skip,take);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        vector<int> dp (n,-1);
        return solve(nums,0,dp);
    }
};