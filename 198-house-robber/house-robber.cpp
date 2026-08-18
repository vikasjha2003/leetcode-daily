class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        int prev1 = 0, prev2 = 0;
        for(int i = n-1; i>= 0; i--) {
            int temp = max(prev1,nums[i] + prev2);
            prev2 = prev1;
            prev1 = temp;
        }

        return prev1;
    }
};