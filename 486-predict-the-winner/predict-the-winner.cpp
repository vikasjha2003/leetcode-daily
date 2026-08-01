class Solution {
public:

    bool solve (vector<int>& nums, int left, int right, int val, bool flag) {
        if(left > right) {
            if(val >= 0) return true;
            return false;
        }

        if(!flag) {
            return solve(nums,left+1,right,val + nums[left],!flag)
            || solve(nums,left,right-1,val + nums[right],!flag);
        } else {
            return solve(nums,left+1,right,val - nums[left],!flag) 
            && solve(nums,left,right-1,val - nums[right],!flag);
        }
    }

    bool predictTheWinner(vector<int>& nums) {
        return solve(nums,0,nums.size()-1,0,false);
    }
};