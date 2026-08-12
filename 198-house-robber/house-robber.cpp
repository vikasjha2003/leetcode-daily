class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev2 = 0;
        int prev1 = 0;

        for(int i = n-1; i>=0; i--) {
            int take = prev2 + nums[i];
            int skip = prev1;

            prev2 = prev1;
            prev1 = max(skip,take);
        }

        return prev1;
    }
};