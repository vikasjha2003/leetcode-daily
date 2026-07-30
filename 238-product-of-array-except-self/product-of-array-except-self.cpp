class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefprod (n);
        int prod = 1;
        for(int i = 0; i<n; i++) {
            prod *= nums[i];
            prefprod[i] = prod;
        }

        vector<int> suffprod(n);
        prod = 1;
        for(int i = n-1; i>=0; i--) {
            prod *= nums[i];
            suffprod[i] = prod;
        }

        vector<int> res (n);

        for(int i = 0; i<n; i++) {
            int a = 1;
            if(i > 0) a *= prefprod[i-1];
            if(i < n-1) a *= suffprod[i+1];

            res[i] = a;
        }

        return res;
    }
};