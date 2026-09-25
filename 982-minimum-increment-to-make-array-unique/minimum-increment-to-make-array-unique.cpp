class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        int n = nums.size();

        sort(nums.begin(),nums.end());

        int res = 0;
        int val = nums[0];
        for(int i = 1; i<n; i++) {
            if(nums[i] <= val) {
                res += val + 1 - nums[i];
                val++;
            } else {
                val = nums[i];
            }
        }

        return res;
    }
};