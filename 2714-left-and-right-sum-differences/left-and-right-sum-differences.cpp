class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();

        vector<int> res (n,0);
        int sum = 0;

        for(int i = 0; i<n; i++) {
            res[i] = sum;
            sum += nums[i];
        }

        sum = 0;

        for(int i = n-1; i >= 0; i--) {
            res[i] = abs(res[i] - sum);
            sum += nums[i];
        }

        return res;
    }
};