class Solution {
public:
    int minElement(vector<int>& nums) {

        int res = INT_MAX;

        for(int i = 0; i<nums.size(); i++) {
            int a = nums[i];
            int sum = 0;

            while(a > 0) {
                sum += a %10;
                a /= 10;
            }

            res = min(res,sum);
        }

        return res;        
    }
};