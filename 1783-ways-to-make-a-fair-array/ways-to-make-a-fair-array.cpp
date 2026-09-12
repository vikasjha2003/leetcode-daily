class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        int sufo = 0, sufe = 0;

        for(int i = n-1; i>= 0; i--) {
            if(i%2==0) sufe += nums[i];
            else sufo += nums[i];
        }

        int ways = 0;

        int prefo = 0;
        int prefe = 0;

        for(int i = 0; i<n; i++) {
            if(i%2==0) sufe -= nums[i];
            else sufo -= nums[i];

            if(prefe + sufo == prefo + sufe) ways++;

            if(i%2==0) prefe += nums[i];
            else prefo += nums[i];
        }
        
        return ways;
    }
};