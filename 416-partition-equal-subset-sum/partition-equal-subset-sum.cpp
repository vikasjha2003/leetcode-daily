class Solution {
public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        
        vector<int> dp (sum+1, false);
        
        dp[0] = true;
        
        for(int i = n-1; i>=0; i--) {
            for(int j = sum; j>=1; j--) {
                if(arr[i] <= j) {
                    dp[j] = dp[j - arr[i]] || dp[j];
                }
            }
        }
        
        return dp[sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum % 2 == 1) return false;
        if(isSubsetSum(nums,sum / 2)) return true;
        return false;
    }
};