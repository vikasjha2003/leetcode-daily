class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<long long,int> mpp;

        int res = 0;
        long long sum = 0;

        for(int i : nums) {
            sum += i;
            if(sum == k) res ++;
            if(mpp.find(sum - k) != mpp.end()) res += mpp[sum-k]; 
            mpp[sum]++;
        }

        return res;
    }
};