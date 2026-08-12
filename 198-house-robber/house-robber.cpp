class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp (n+2,0);

        for(int i = n-1; i>=0; i--) {
            int take = dp[i+2] + nums[i];
            int skip = dp[i+1];

            dp[i] = max(skip,take);
        }

        return dp[0];
    }
};