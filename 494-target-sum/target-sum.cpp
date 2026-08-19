class Solution {
public:
    int n;
    int solve(vector<int> &nums, int idx, int target) {
        if(idx == n) {
            if(target == 0) return 1;
            return 0;
        } 

        int skip = solve(nums,idx+1,target);
        int take = 0;
        if(nums[idx] <= target) {
            take = solve(nums,idx+1,target - nums[idx]);
        }

        return skip + take;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum < target || (sum - target) % 2 == 1) return 0;

        return solve(nums,0,(sum-target)/2);
    }
};