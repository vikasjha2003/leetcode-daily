class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i = 0; i<n; i++) {
            if(nums[i] < 0 && k > 0) {
                nums[i] = -nums[i];
                k--;
            } else break;
        } 


        int mini = 0;
        for(int i = 1; i<n; i++) {
            if(nums[i] < nums[mini]) {
                mini = i;
            }
        }

        int res = 0;
        for(int i = 0; i<n; i++) {
            if(i == mini && k > 0 && k%2==1) {
                nums[i] = -nums[i];
                k = 0;
            }
            res += nums[i];
        }

        return res;
    }
};