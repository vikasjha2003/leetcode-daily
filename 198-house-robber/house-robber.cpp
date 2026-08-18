class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev1 = 0, prev2 = 0;
        for(int i = n-1; i>= 0; i--) {
            int skip = prev1;
            int take = nums[i] + prev2;

            prev2 = prev1;
            prev1 = max(skip,take);
        }
        return prev1;
    }
};