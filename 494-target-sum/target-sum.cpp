class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum < target || (sum - target) % 2 == 1) return 0;

        vector<vector<int>> dp (n+1,vector<int> ((sum-target)/2+1,0));
        dp[n][0] = 1;
        
        for(int i = n-1; i>= 0; i--) {
            for(int j = (sum-target)/2; j >= 0; j--) {
                int skip = dp[i+1][j];
                int take = 0;
                if(nums[i] <= j) {
                    take = dp[i+1][j-nums[i]];
                }
                
                dp[i][j] = skip + take;
            }
        }
        
        return dp[0][(sum-target)/2];        
    }
};