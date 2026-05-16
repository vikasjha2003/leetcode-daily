class Solution {
    public int findMin(int[] nums) {
        int mini = Integer.MAX_VALUE;
        for(int num : nums) {
            mini = Math.min(num,mini);
        }
        return mini;
    }
}