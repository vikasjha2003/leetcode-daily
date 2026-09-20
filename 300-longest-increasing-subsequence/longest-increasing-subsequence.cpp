class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int solve(vector<int>& nums, int idx , int last) {
        if(idx == n) return 0;
        if(dp[idx][last+1] != -1) return dp[idx][last+1];

        int skip = solve(nums,idx+1,last);
        int take = 0;
        if(last == -1 || nums[last] < nums[idx]) {
            take = 1 + solve(nums,idx+1,idx);
        }

        return dp[idx][last+1] = max(skip , take);
    }
    int lengthOfLIS(vector<int>& nums) {
        n = nums.size();
        dp.resize(n,vector<int> (n+1,-1));
        return solve(nums,0,-1);
    }
};