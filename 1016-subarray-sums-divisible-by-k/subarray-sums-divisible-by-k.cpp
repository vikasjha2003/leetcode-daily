class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();

        unordered_map<int,int> mpp;
        int res = 0;
        int sum = 0;
        for(int i = 0; i<n; i++) {
            sum = (sum + nums[i]) % k;
            int val = (sum + k) % k;
            if(val == 0) res++;
            if(mpp.find(val) != mpp.end()) res += mpp[val];
            mpp[val]++;
        }

        return res;
    }
};