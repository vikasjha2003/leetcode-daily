class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum < target || (sum - target) % 2 == 1) return 0;

        vector<int> dp ((sum-target)/2+1,0);
        dp[0] = 1;
        
        for(int i = n-1; i>= 0; i--) {
            for(int j = (sum-target)/2; j >= 0; j--) {
                int skip = dp[j];
                int take = 0;
                if(nums[i] <= j) {
                    take = dp[j-nums[i]];
                }
                
                dp[j] = skip + take;
            }
        }
        
        return dp[(sum-target)/2];        
    }
};