class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mpp;
        int sum = nums[0]%k;
        mpp[sum] = 0;
        for(int i = 1; i<n; i++) {
            sum = (sum + nums[i]) % k;
            if(sum == 0) return true;
            if(mpp.find(sum) != mpp.end()) {
                if(i - mpp[sum] == 1) continue;
                return true;
            }
            mpp[sum] = i;
        }
        return false;
    }
};