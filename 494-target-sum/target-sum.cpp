class Solution {
public:
    int n;
    int solve(vector<int> &nums, int idx, int target, vector<vector<int>> &dp) {
        if(idx == n) {
            if(target == 0) return 1;
            return 0;
        } 
        if(dp[idx][target] != -1) return dp[idx][target];

        int skip = solve(nums,idx+1,target,dp);
        int take = 0;
        if(nums[idx] <= target) {
            take = solve(nums,idx+1,target - nums[idx],dp);
        }

        return dp[idx][target] = skip + take;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum < target || (sum - target) % 2 == 1) return 0;

        vector<vector<int>> dp (n,vector<int> ((sum-target)/2+1,-1));

        return solve(nums,0,(sum-target)/2,dp);
    }
};