class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> prefprod (n);
        vector<int> suffprod(n);
        int prod1 = 1;
        int prod2 = 1;
        
        for(int i = 0; i<n; i++) {
            prod1 *= nums[i];
            prefprod[i] = prod1;

            prod2 *= nums[n-i-1];
            suffprod[n-i-1] = prod2;
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