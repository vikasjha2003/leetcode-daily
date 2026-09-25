class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size();

        bool flag = false;
        for(int i = 1; i<n; i++) {
            if(nums[i-1] > nums[i]) {
                if(!flag) {
                    flag = true;
                    if(i - 1 != 0 && nums[i-2] > nums[i]) {
                        nums[i] = nums[i-1];
                    }
                }
                else return false;
            }
        }

        return true;
    }
};