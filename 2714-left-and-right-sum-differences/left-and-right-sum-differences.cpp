class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> res (n,0);
        int sum = accumulate(nums.begin(),nums.end(), 0);
        int lsum = 0;

        for(int i = 0; i<n; i++) {
            sum -= nums[i];
            res[i] = abs(lsum - sum);
            lsum += nums[i];
        }

        return res;
    }
};