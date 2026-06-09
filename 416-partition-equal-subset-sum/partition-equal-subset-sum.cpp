class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<vector<int>> dp (n+1, vector<int> (sum + 1, false));
        
        for(int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        
        for(int i = n-1; i >= 0; i--) {
            for(int j = sum; j > 0; j--) {
                bool skip = dp[i+1][j];
                bool take = false;
                if(arr[i] <= j) take = dp[i+1][j - arr[i]];
                dp[i][j] = skip || take;
            }
        }
        
        return dp[0][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        return sum % 2 ? false : isSubsetSum(nums,sum/2);
    }
};