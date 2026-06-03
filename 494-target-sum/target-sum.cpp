class Solution {
public:
    int n;
    int solve (vector<int> &nums, int target, int idx) {
        if(idx == n) {
            if(target == 0) return 1;
            return 0;
        }

        int plus = solve(nums,target + nums[idx],idx+1);
        int minus = solve(nums,target - nums[idx], idx+1);

        return plus + minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n = nums.size();
        return solve(nums,target,0);
    }
};