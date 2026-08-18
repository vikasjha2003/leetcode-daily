class Solution {
public:

    // Brute Force

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();

        int low = *min_element(nums.begin(),nums.end());
        int high = *max_element(nums.begin(),nums.end());
        long long resCost = LLONG_MAX;
        while(low <= high) {
            int mid = low + (high - low)/2;
            long long cst1 = 0;
            long long cst2 = 0;
            for(int i = 0; i<n; i++) {
                cst1 += abs(mid - nums[i]) * (long long)(cost[i]);
                cst2 += abs(mid - 1 - nums[i]) * (long long)(cost[i]);
            }

            if(cst1 < cst2) {
                resCost = min(resCost,cst1);
                low = mid+1;
            } else {
                resCost = min(resCost,cst2);
                high = mid-1;
            }
        }

        return resCost;
    }
};