class Solution {
    public void moveZeroes(int[] nums) {
        int i = 0;
        for(int j = 0; j<nums.length; j++) {
            if(nums[i] != 0) i++;
            else if (nums[j] != 0){
                nums[i] = nums[j];
                nums[j] = 0;
                i++;
            }
        }
    }
}