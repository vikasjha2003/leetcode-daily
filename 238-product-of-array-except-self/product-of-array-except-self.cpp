class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> suffprod(n);
        int prod = 1;

        for(int i = 0; i<n; i++) {
            prod *= nums[n-i-1];
            suffprod[n-i-1] = prod;
        }

        vector<int> res (n);
        prod = 1;

        for(int i = 0; i<n; i++) {
            int a = prod;
            if(i < n-1) a *= suffprod[i+1];

            res[i] = a;

            prod *= nums[i];
        }

        return res;
    }
};