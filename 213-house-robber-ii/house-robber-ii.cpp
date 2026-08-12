class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];

        int prev1 = 0;
        int prev2 = 0;

        for(int i = n-1; i> 0; i--) {
            int take = nums[i] + prev2;
            int skip = prev1;

            prev2 = prev1;
            prev1 = max(skip,take);
        }

        int prev3 = 0;
        int prev4 = 0;

        for(int i = n-2; i>= 0; i--) {
            int take = nums[i] + prev4;
            int skip = prev3;

            prev4 = prev3;
            prev3 = max(skip,take);
        }

        return max(prev1,prev3);
    }
};